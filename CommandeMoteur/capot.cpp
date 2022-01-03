#include "capot.h"

Capot::Capot( MccUldaq &_laCarte, int _numDio, QObject *parent) : QObject(parent),
    numDio(_numDio),
    laCarte(_laCarte)
{

    laCarte.ulDConfigBit(numDio,DD_INPUT);
    laCarte.ulDBitIn(numDio,etatCapot);
    connect(&timerCapot,&QTimer::timeout,this,&Capot::onTimerCapot_Timeout);
    timerCapot.start(TEMPO_CAPOT);
}

void Capot::onTimerCapot_Timeout()
{
   bool etatCourant;
    laCarte.ulDBitIn(numDio,etatCourant);
    if(etatCourant !=etatCapot)
    {
        emit EtatCapotChange(etatCourant);
        etatCapot = etatCourant;
    }

}
