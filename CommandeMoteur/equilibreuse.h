#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include "mcculdaq.h"
#include "capot.h"
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(Capot *_leCapot, MccUldaq *_laCarte, QWidget *parent = nullptr);
    ~Equilibreuse();

private:
    Ui::Equilibreuse *ui;
    MccUldaq *laCarte;
    Capot *leCapot;
    void OnEtatCapotChange(bool _etat);
    QLabel labelEtatCapot;

};
#endif // EQUILIBREUSE_H
