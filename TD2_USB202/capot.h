#ifndef CAPOT_H
#define CAPOT_H

#include <QObject>
#include <mcculdaq.h>
class Capot : public QObject
{
    Q_OBJECT
public:
    explicit Capot(MccUldaq &laCarte,int _numDio,QObject *parent = nullptr);

private:
    bool etatCapot;
    int numDio;

signals:
    void EtatCapotChange(bool etat);
};

#endif // CAPOT_H
