#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include <QLabel>
#include <QtCharts>
#include "mcculdaq.h"
#include "capot.h"
#include "moteur.h"
#include "codeur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

public slots:
    void onCapot_EtatCapotChange(bool _etat);
    void onCodeur_VitesseChange(int _vitesse);
     void onTimerMesure_timeout();

private slots:
    void on_pushButton_LancerMoteur_clicked();
    void on_pushButton_Arreter_clicked();


    void on_pushButton_LancerAcquisition_clicked();

private:
    Ui::Equilibreuse *ui;
    MccUldaq laCarte;
    Capot *leCapot;
    Codeur *leCodeur;
    QLabel labelEtatCapot;

    Moteur *leMoteur;

    QTimer timerMesure;

    double *valeursBrutes;

    QChartView *chartView;
    QHBoxLayout *layout;
    QSplineSeries courbeA;
    QSplineSeries courbeO;
    QChart chart;
};
#endif // EQUILIBREUSE_H
