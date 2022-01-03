#ifndef REGLAGESM18_H
#define REGLAGESM18_H

#include <QMainWindow>
#include <uldaq.h>
#include <mcculdaq.h>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class ReglageSM18; }
QT_END_NAMESPACE

class ReglageSM18 : public QMainWindow
{
    Q_OBJECT

public:
    ReglageSM18(QWidget *parent = nullptr);
    ~ReglageSM18();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ReglageSM18 *ui;
    bool estentreindemesurer = false;
    QTimer timer;
    void onQtimerTimeout();
    MccUldaq *laCarte;

};
#endif // REGLAGESM18_H
