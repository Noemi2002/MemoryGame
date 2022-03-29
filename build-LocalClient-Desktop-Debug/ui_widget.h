/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *conectar;
    QLabel *instruccion1;
    QLabel *instrucciones2;
    QLabel *instrucciones3;
    QLabel *instrucciones4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(790, 204);
        conectar = new QPushButton(Widget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(400, 140, 111, 25));
        instruccion1 = new QLabel(Widget);
        instruccion1->setObjectName(QString::fromUtf8("instruccion1"));
        instruccion1->setGeometry(QRect(30, 30, 811, 21));
        instrucciones2 = new QLabel(Widget);
        instrucciones2->setObjectName(QString::fromUtf8("instrucciones2"));
        instrucciones2->setGeometry(QRect(30, 50, 811, 41));
        instrucciones3 = new QLabel(Widget);
        instrucciones3->setObjectName(QString::fromUtf8("instrucciones3"));
        instrucciones3->setGeometry(QRect(30, 90, 761, 17));
        instrucciones4 = new QLabel(Widget);
        instrucciones4->setObjectName(QString::fromUtf8("instrucciones4"));
        instrucciones4->setGeometry(QRect(30, 120, 781, 17));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        conectar->setText(QApplication::translate("Widget", "Iniciar Juego", nullptr));
        instruccion1->setText(QApplication::translate("Widget", "\302\241Bienvenido a Memory game.", nullptr));
        instrucciones2->setText(QApplication::translate("Widget", "Pueden jugar dos jugares a la vez, cada uno llevar\303\241 su propio puntaje.", nullptr));
        instrucciones3->setText(QApplication::translate("Widget", "No es necesario que se registren con alg\303\272n nombre, solamente que eligan entre ustedes el orden a jugar", nullptr));
        instrucciones4->setText(QApplication::translate("Widget", "Para iniciar el juego, darle click al siguiente bot\303\263n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
