#include "capot.h"

Capot::Capot( MccUldaq &_laCarte, int _numDio, QObject *parent) : QObject(parent),
    numDio(_numDio),
    laCarte(_laCarte)
{
    connect(&timerCapot,&QTimer::timeout,this,&Capot::onTimerCapot_Timeout)
}
