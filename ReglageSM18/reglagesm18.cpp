#include "reglagesm18.h"
#include "ui_reglagesm18.h"

ReglageSM18::ReglageSM18(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReglageSM18)
{

    ui->setupUi(this);
    laCarte = new MccUldaq();
    connect(&timer,&QTimer::timeout,this,&ReglageSM18::onQtimerTimeout);
}

ReglageSM18::~ReglageSM18()
{
    delete ui;
}


void ReglageSM18::on_pushButton_clicked()
{
    if (estentreindemesurer == false){
        timer.start(500);
        estentreindemesurer = true;
        ui->pushButton->setText("arreter Mesure");
    }
    else{
        timer.stop();
        estentreindemesurer = false;
        ui->pushButton->setText("Lancer Mesure");
    }
}

void ReglageSM18::onQtimerTimeout()
{
    laCarte->ulAInScan()
   double value;
   laCarte->ulAIn(0,value);
   ui->lcdNumber->display(value);
}
