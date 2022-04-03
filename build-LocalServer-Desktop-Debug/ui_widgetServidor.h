/********************************************************************************
** Form generated from reading UI file 'widgetServidor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSERVIDOR_H
#define UI_WIDGETSERVIDOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget;
    QLabel *Servidor_Guia;
    QPushButton *iniciar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(396, 257);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 371, 192));
        Servidor_Guia = new QLabel(Widget);
        Servidor_Guia->setObjectName(QString::fromUtf8("Servidor_Guia"));
        Servidor_Guia->setGeometry(QRect(10, 10, 138, 17));
        iniciar = new QPushButton(Widget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        iniciar->setGeometry(QRect(280, 10, 110, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        Servidor_Guia->setText(QApplication::translate("Widget", "Interfaz del servidor", nullptr));
        iniciar->setText(QApplication::translate("Widget", "Iniciar Servidor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSERVIDOR_H
