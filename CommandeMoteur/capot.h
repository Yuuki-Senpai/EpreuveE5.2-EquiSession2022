#ifndef CAPOT_H
#define CAPOT_H

#include <QTimer>
#include <QObject>
#include "mcculdaq.h"

class Capot : public QObject
{
    Q_OBJECT
private:
    bool etatCapot;
    int numDio;
     MccUldaq &laCarte;
     QTimer timerCapot;

public:
    explicit Capot( MccUldaq &_laCarte, int _numDio, QObject *parent = nullptr);
    void onTimerCapot_Timeout();

signals:
    void EtatCapotChange(bool etat);
};

#endif // CAPOT_H
