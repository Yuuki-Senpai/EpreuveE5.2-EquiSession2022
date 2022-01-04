#ifndef CODEUR_H
#define CODEUR_H

#include <QObject>
#include <QTimer>
#include <mcculdaq.h>
#include <QDebug>
#include <constantes.h>
class Codeur : public QObject
{
    Q_OBJECT
private:
    MccUldaq &laCarte;
    int numDio;
public:
    explicit Codeur(MccUldaq &_laCarte, const int _numDio,QObject *parent = nullptr);
public:
    int vitesse;
    void landerMesureVitesse();
    void ArreterMesureVitesse();
    QTimer timerVitesse;
signals:
    void VitesseChange(int vit);
private slots:
    void onTimerVitesse_Timeout();
};

#endif // CODEUR_H
