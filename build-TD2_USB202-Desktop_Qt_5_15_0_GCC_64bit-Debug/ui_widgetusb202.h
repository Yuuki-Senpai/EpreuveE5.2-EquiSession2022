/********************************************************************************
** Form generated from reading UI file 'widgetusb202.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETUSB202_H
#define UI_WIDGETUSB202_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetUSB202
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Quitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_BP1;
    QLabel *label_BP2;
    QLabel *label_BP3;
    QLabel *label_BP4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_LED1;
    QCheckBox *checkBox_LED2;
    QCheckBox *checkBox_LED3;
    QCheckBox *checkBox_LED4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WidgetUSB202)
    {
        if (WidgetUSB202->objectName().isEmpty())
            WidgetUSB202->setObjectName(QString::fromUtf8("WidgetUSB202"));
        WidgetUSB202->resize(310, 214);
        centralwidget = new QWidget(WidgetUSB202);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Quitter = new QPushButton(centralwidget);
        pushButton_Quitter->setObjectName(QString::fromUtf8("pushButton_Quitter"));
        pushButton_Quitter->setGeometry(QRect(190, 60, 80, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 50, 92, 110));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_BP1 = new QLabel(widget);
        label_BP1->setObjectName(QString::fromUtf8("label_BP1"));

        verticalLayout->addWidget(label_BP1);

        label_BP2 = new QLabel(widget);
        label_BP2->setObjectName(QString::fromUtf8("label_BP2"));

        verticalLayout->addWidget(label_BP2);

        label_BP3 = new QLabel(widget);
        label_BP3->setObjectName(QString::fromUtf8("label_BP3"));

        verticalLayout->addWidget(label_BP3);

        label_BP4 = new QLabel(widget);
        label_BP4->setObjectName(QString::fromUtf8("label_BP4"));

        verticalLayout->addWidget(label_BP4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox_LED1 = new QCheckBox(widget);
        checkBox_LED1->setObjectName(QString::fromUtf8("checkBox_LED1"));

        verticalLayout_2->addWidget(checkBox_LED1);

        checkBox_LED2 = new QCheckBox(widget);
        checkBox_LED2->setObjectName(QString::fromUtf8("checkBox_LED2"));

        verticalLayout_2->addWidget(checkBox_LED2);

        checkBox_LED3 = new QCheckBox(widget);
        checkBox_LED3->setObjectName(QString::fromUtf8("checkBox_LED3"));

        verticalLayout_2->addWidget(checkBox_LED3);

        checkBox_LED4 = new QCheckBox(widget);
        checkBox_LED4->setObjectName(QString::fromUtf8("checkBox_LED4"));

        verticalLayout_2->addWidget(checkBox_LED4);


        horizontalLayout->addLayout(verticalLayout_2);

        WidgetUSB202->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WidgetUSB202);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 310, 21));
        WidgetUSB202->setMenuBar(menubar);
        statusbar = new QStatusBar(WidgetUSB202);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WidgetUSB202->setStatusBar(statusbar);

        retranslateUi(WidgetUSB202);

        QMetaObject::connectSlotsByName(WidgetUSB202);
    } // setupUi

    void retranslateUi(QMainWindow *WidgetUSB202)
    {
        WidgetUSB202->setWindowTitle(QCoreApplication::translate("WidgetUSB202", "WidgetUSB202", nullptr));
        pushButton_Quitter->setText(QCoreApplication::translate("WidgetUSB202", "Quitter", nullptr));
        label_BP1->setText(QCoreApplication::translate("WidgetUSB202", "BP1", nullptr));
        label_BP2->setText(QCoreApplication::translate("WidgetUSB202", "BP2", nullptr));
        label_BP3->setText(QCoreApplication::translate("WidgetUSB202", "BP3", nullptr));
        label_BP4->setText(QCoreApplication::translate("WidgetUSB202", "BP4", nullptr));
        checkBox_LED1->setText(QCoreApplication::translate("WidgetUSB202", "LED1", nullptr));
        checkBox_LED2->setText(QCoreApplication::translate("WidgetUSB202", "LED2", nullptr));
        checkBox_LED3->setText(QCoreApplication::translate("WidgetUSB202", "LED3", nullptr));
        checkBox_LED4->setText(QCoreApplication::translate("WidgetUSB202", "LED4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetUSB202: public Ui_WidgetUSB202 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETUSB202_H
