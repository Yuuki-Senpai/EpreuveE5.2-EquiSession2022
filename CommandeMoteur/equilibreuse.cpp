#include "equilibreuse.h"
#include "ui_equilibreuse.h"


Equilibreuse::Equilibreuse(Capot *_leCapot, MccUldaq *_laCarte, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Equilibreuse),
      laCarte(_laCarte),
      leCapot(_leCapot)
{
    connect(leCapot,&Capot::EtatCapotChange,&Equilibreuse::OnEtatCapotChange);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    ui->setupUi(this);
}

Equilibreuse::~Equilibreuse()
{
    delete [] laCarte;
    delete [] leCapot;
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
        labelEtatCapot.setText("| Capot ..... |");
    }
    else
    {
        palette.setColor(QPalette::WindowText,Qt::red);
        labelEtatCapot.setPalette(palette);
        labelEtatCapot.setText("| Capot ..... |");
    }
}

