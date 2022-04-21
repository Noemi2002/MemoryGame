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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *plainTextEdit_memoriaUso;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_memoria;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_disco;
    QLabel *label_5;
    QLabel *label_Puntaje;
    QLabel *label_PF;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(485, 372);
        plainTextEdit_memoriaUso = new QPlainTextEdit(Widget);
        plainTextEdit_memoriaUso->setObjectName(QString::fromUtf8("plainTextEdit_memoriaUso"));
        plainTextEdit_memoriaUso->setGeometry(QRect(10, 30, 191, 91));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 171, 17));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 140, 141, 17));
        plainTextEdit_memoria = new QPlainTextEdit(Widget);
        plainTextEdit_memoria->setObjectName(QString::fromUtf8("plainTextEdit_memoria"));
        plainTextEdit_memoria->setGeometry(QRect(10, 170, 191, 191));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 20, 151, 17));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 140, 141, 17));
        plainTextEdit_disco = new QPlainTextEdit(Widget);
        plainTextEdit_disco->setObjectName(QString::fromUtf8("plainTextEdit_disco"));
        plainTextEdit_disco->setGeometry(QRect(240, 170, 191, 191));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(240, 50, 151, 17));
        label_Puntaje = new QLabel(Widget);
        label_Puntaje->setObjectName(QString::fromUtf8("label_Puntaje"));
        label_Puntaje->setGeometry(QRect(400, 20, 67, 17));
        label_PF = new QLabel(Widget);
        label_PF->setObjectName(QString::fromUtf8("label_PF"));
        label_PF->setGeometry(QRect(330, 50, 67, 17));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Uso de memoria", nullptr));
        label_2->setText(QApplication::translate("Widget", "Cartas en memoria", nullptr));
        label_3->setText(QApplication::translate("Widget", "Puntaje del jugaodr:", nullptr));
        label_4->setText(QApplication::translate("Widget", "Cartas en disco", nullptr));
        label_5->setText(QApplication::translate("Widget", "Page fault:", nullptr));
        label_Puntaje->setText(QApplication::translate("Widget", "0", nullptr));
        label_PF->setText(QApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
