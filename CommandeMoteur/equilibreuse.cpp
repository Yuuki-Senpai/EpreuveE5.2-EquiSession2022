#include "equilibreuse.h"
#include "ui_equilibreuse.h"


Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Equilibreuse)

{
    laCarte = new MccUldaq();
    leCapot = new Capot(*laCarte,0,this);
    leMoteur = new Moteur(*laCarte,0);

    connect(leCapot,&Capot::EtatCapotChange,this,&Equilibreuse::OnEtatCapotChange);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    ui->setupUi(this);
}

Equilibreuse::~Equilibreuse()
{
    delete [] laCarte;
    delete [] leCapot;
    delete [] leMoteur;
    delete ui;
}

void Equilibreuse::OnEtatCapotChange(bool _etat)
{
    QPalette palette;
    labelEtatCapot.setAutoFillBackground(true);
    if(_etat)
    {
        palette.setColor(QPalette::WindowText,Qt::black);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot fermé |");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot ouvert |");
    }
}


void Equilibreuse::on_pushButton_Arreter_clicked()
{

}

void Equilibreuse::on_pushButton_Lancer_clicked()
{

}
