/********************************************************************************
** Form generated from reading UI file 'widgetcourbes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCOURBES_H
#define UI_WIDGETCOURBES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetCourbes
{
public:
    QWidget *widgetCourbes;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Lancer;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Quitter;

    void setupUi(QWidget *WidgetCourbes)
    {
        if (WidgetCourbes->objectName().isEmpty())
            WidgetCourbes->setObjectName(QString::fromUtf8("WidgetCourbes"));
        WidgetCourbes->resize(800, 506);
        widgetCourbes = new QWidget(WidgetCourbes);
        widgetCourbes->setObjectName(QString::fromUtf8("widgetCourbes"));
        widgetCourbes->setGeometry(QRect(10, 10, 771, 431));
        widget = new QWidget(WidgetCourbes);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 460, 731, 34));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Lancer = new QPushButton(widget);
        pushButton_Lancer->setObjectName(QString::fromUtf8("pushButton_Lancer"));
        QFont font;
        font.setPointSize(16);
        pushButton_Lancer->setFont(font);

        horizontalLayout->addWidget(pushButton_Lancer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Quitter = new QPushButton(widget);
        pushButton_Quitter->setObjectName(QString::fromUtf8("pushButton_Quitter"));
        pushButton_Quitter->setFont(font);

        horizontalLayout->addWidget(pushButton_Quitter);


        retranslateUi(WidgetCourbes);
        QObject::connect(pushButton_Quitter, SIGNAL(clicked()), WidgetCourbes, SLOT(close()));

        QMetaObject::connectSlotsByName(WidgetCourbes);
    } // setupUi

    void retranslateUi(QWidget *WidgetCourbes)
    {
        WidgetCourbes->setWindowTitle(QCoreApplication::translate("WidgetCourbes", "Affichage des courbes", nullptr));
        pushButton_Lancer->setText(QCoreApplication::translate("WidgetCourbes", "Lancer", nullptr));
        pushButton_Quitter->setText(QCoreApplication::translate("WidgetCourbes", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetCourbes: public Ui_WidgetCourbes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCOURBES_H
