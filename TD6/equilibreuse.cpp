#include "equilibreuse.h"
#include "ui_equilibreuse.h"
#include "constantes.h"
#include <QMessageBox>

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    leCapot = new Capot(laCarte, DIO0);
    connect(leCapot,&Capot::EtatCapotChange,this,&Equilibreuse::onCapot_EtatCapotChange);
    leCodeur = new Codeur(laCarte);
    connect(leCodeur,&Codeur::VitesseChange,this,&Equilibreuse::onCodeur_VitesseChange);
    leMoteur = new Moteur(laCarte, AOUT0);
    onCapot_EtatCapotChange(leCapot->getEtatCapot());
    timerMesure.setTimerType(Qt::PreciseTimer);
    connect(&timerMesure,&QTimer::timeout,this,&Equilibreuse::onTimerMesure_timeout);

    courbeA.setName("Palier A");
    courbeO.setName("Palier O");


    chartView = new QChartView(&chart);
    layout = new QHBoxLayout(ui->widgetCourbes);
    layout->addWidget(chartView);
    chart.addSeries(&courbeA);
    chart.addSeries(&courbeO);
    chart.createDefaultAxes();

    QList<QAbstractAxis *> axe = chart.axes();
    if(axe.size() == 2)
    {
        QValueAxis *axeY = static_cast<QValueAxis *>(axe.last());
        axeY->applyNiceNumbers();
        axeY->setTickCount(5);
        axeY->setMinorTickCount(2);
        axeY->setLabelFormat("%d");
        axeY->setMin(-10);
        axeY->setMax(+10);

        QValueAxis *axeX = static_cast<QValueAxis *>(axe.first());
        axeX->setLabelFormat("%d");
        axeX->setMax(NB_ECHANTILLONS_PAR_CANAL);
    }
    valeursBrutes = new double[NB_ECHANTILLONS_PAR_CANAL * NB_CANAUX];
}

Equilibreuse::~Equilibreuse()
{
    delete ui;
    delete leCapot;
}

void Equilibreuse::onCapot_EtatCapotChange(bool _etat)
{
    QPalette palette;
    labelEtatCapot.setAutoFillBackground(true);
    if(_etat)
    {
        palette.setColor(QPalette::WindowText,Qt::black);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot fermé|");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot ouvert |");
        on_pushButton_Arreter_clicked();
    }
}

void Equilibreuse::onCodeur_VitesseChange(int _vitesse)
{
    ui->lcdNumber_vitesse->display(_vitesse);
}

void Equilibreuse::onTimerMesure_timeout()
{
    float x;
    float y;
    ScanStatus status;
    TransferStatus transferStatus;
    UlError erreur = laCarte.ulAInScanStatus(status,transferStatus);
    if(erreur != ERR_NO_ERROR)
    {
        qDebug()<< "ulAInScanStatus " << erreur;
        qDebug() <<"Status " << status;
    }
    else
    {
        if(status == SS_RUNNING)
        {
            int index = transferStatus.currentIndex;
            int totalEchantillons = transferStatus.currentTotalCount;

            courbeA.clear();
            courbeO.clear();
            if(totalEchantillons > NB_ECHANTILLONS_PAR_CANAL)
                index = NB_ECHANTILLONS_PAR_CANAL;
            for (int i=0;i<index*NB_CANAUX;i+=NB_CANAUX) {
                x  = (i*360)/1000.0;
                courbeA << QPointF(i,valeursBrutes[i]);
                y = valeursBrutes[i+1];//manque l'attenuationFiltre;
                courbeO << QPointF(i,valeursBrutes[i+1]);
            }
            chartView->setRenderHint(QPainter::Antialiasing);
        }
    }
}


void Equilibreuse::on_pushButton_LancerMoteur_clicked()
{
    if(ui->pushButton_LancerMoteur->text()=="Lancer Moteur")
    {
        ui->pushButton_LancerMoteur->setText("Fixer consigne");
    }
    leMoteur->FixerConsigneVitesse(ui->dial_ConsigneVItesse->value());
    leCodeur->LancerMesureVitesse();

}

void Equilibreuse::on_pushButton_Arreter_clicked()
{
    ui->pushButton_LancerMoteur->setText("Lancer Moteur");
    leMoteur->FixerConsigneVitesse(0);
    ui->dial_ConsigneVItesse->setValue(0);
    leCodeur->ArreterMessureVitesse();
    ui->lcdNumber_vitesse->display(0);
}



void Equilibreuse::on_pushButton_LancerAcquisition_clicked()
{
    double vitesse = 33000;
    UlError erreur;
    if(ui->pushButton_LancerAcquisition->text()=="Lancer Acquisition")
    {
        ScanOption options = static_cast<ScanOption>(SO_SINGLEIO | SO_CONTINUOUS | SO_EXTCLOCK | SO_EXTTRIGGER);
        //qDebug() << "scanOption : " << Qt::hex << options;
        AInScanFlag flags = AINSCAN_FF_DEFAULT ;
        erreur = laCarte.ulAInScan(CH0,CH1,NB_ECHANTILLONS_PAR_CANAL,&vitesse,options,flags,valeursBrutes);
        if(erreur != ERR_NO_ERROR)
        {
            qDebug()<< "ulAInScan " << erreur;
        }
        else
        {
            timerMesure.start(1500);
            ui->pushButton_LancerAcquisition->setText("Arrêter");
        }
    }
    else
    {
        timerMesure.stop();
        erreur = laCarte.ulAInScanStop();
        if(erreur != ERR_NO_ERROR)
        {
            qDebug()<< "ulAInScanStop " << erreur;
        }
        ui->pushButton_LancerAcquisition->setText("Lancer Acquisition");
        courbeA.clear();
        courbeO.clear();
        chartView->setRenderHint(QPainter::Antialiasing);

    }
}
