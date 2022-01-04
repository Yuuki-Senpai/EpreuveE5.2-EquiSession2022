#include "codeur.h"
#include <QDebug>



Codeur::Codeur(MccUldaq &_laCarte, QObject *parent):
    QObject(parent),
    laCarte(_laCarte),
    vitesse(0)
{
    connect(&timerVitesse,&QTimer::timeout,this,&Codeur::onTimerVitesse_timeout);
    timerVitesse.setTimerType(Qt::PreciseTimer);
    timerVitesse.setSingleShot(true);
}

Codeur::~Codeur()
{
    disconnect(&timerVitesse,&QTimer::timeout,this,&Codeur::onTimerVitesse_timeout);
}

void Codeur::LancerMesureVitesse()
{
    UlError erreur;
    erreur = laCarte.UlCClear();
    if(erreur == ERR_NO_ERROR)
            timerVitesse.start(TEMPO_VITESSE);
    else
        qDebug() << "Lancer Mesure Vitesse Code erreur MccUldaq : " << erreur ;
}

void Codeur::ArreterMessureVitesse()
{
    timerVitesse.stop();
    vitesse = 0 ;
}

void Codeur::onTimerVitesse_timeout()
{
    long valCpt;
    UlError erreur;
    erreur = laCarte.ulCIn(valCpt);
    if(erreur == ERR_NO_ERROR)
    {
        int vitesseCalculee = valCpt / NB_IMPULSIONS_PAR_TOUR * 60 ;
        if(vitesseCalculee != vitesse)
        {
            emit VitesseChange(vitesseCalculee);
            vitesse = vitesseCalculee;
        }
        erreur = laCarte.UlCClear();
        if(erreur == ERR_NO_ERROR)
            timerVitesse.start(TEMPO_VITESSE);
        else
            qDebug() << "onTimerVitess_timeout : ulCClear " << erreur ;
    }
    else
        qDebug() << "onTimerVitess_timeout : ulCIn " << erreur ;
}
