#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include "mcculdaq.h"
#include "capot.h"
#include "moteur.h"
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

private slots:
    void on_pushButton_Arreter_clicked();
    void on_pushButton_Lancer_clicked();
public slots:
    void OnEtatCapotChange(bool _etat);

private:
    Ui::Equilibreuse *ui;
    MccUldaq *laCarte;
    Capot *leCapot;
    Moteur *leMoteur;
    QLabel labelEtatCapot;

};
#endif // EQUILIBREUSE_H
