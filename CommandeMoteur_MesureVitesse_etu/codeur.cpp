#include "codeur.h"

Codeur::Codeur(MccUldaq &_laCarte, const int _numDio, QObject *parent):QObject(parent),laCarte(_laCarte),numDio(_numDio)
{
    connect(&timerVitesse,&QTimer::timeout,this,&Codeur::onTimerVitesse_Timeout);
    timerVitesse.setTimerType(Qt::PreciseTimer);
    timerVitesse.setSingleShot(true);
}

void Codeur::landerMesureVitesse()
{
    UlError erreur;
    erreur=laCarte.UlCClear();
    if (erreur!=0){
        qDebug()<< "Erreur ulcIn : "<< erreur;
    }
    timerVitesse.start(TEMPO_VITESSE);
}

void Codeur::ArreterMesureVitesse()
{
    timerVitesse.stop();
}

void Codeur::onTimerVitesse_Timeout(){
    UlError erreur;

    long valCpt;
    erreur = laCarte.ulCIn(valCpt);
    timerVitesse.start(TEMPO_VITESSE);
    if (erreur!=0){
        qDebug()<< "Erreur ulcIn : "<< erreur;
    }
    else {
        int vitesseCalculer = valCpt/1000*60;
        if (vitesseCalculer !=vitesse){
            emit VitesseChange(vitesseCalculer);
            vitesse = vitesseCalculer;
        }

    }

}
