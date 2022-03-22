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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *mensaje;
    QLineEdit *msj;
    QPushButton *iniciar;
    QPushButton *enviar;
    QPushButton *quitar;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *puerto;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(264, 119);
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mensaje = new QLabel(Widget);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));

        gridLayout->addWidget(mensaje, 0, 0, 1, 1);

        msj = new QLineEdit(Widget);
        msj->setObjectName(QString::fromUtf8("msj"));

        gridLayout->addWidget(msj, 0, 1, 1, 3);

        iniciar = new QPushButton(Widget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));

        gridLayout->addWidget(iniciar, 1, 0, 1, 2);

        enviar = new QPushButton(Widget);
        enviar->setObjectName(QString::fromUtf8("enviar"));

        gridLayout->addWidget(enviar, 1, 2, 1, 1);

        quitar = new QPushButton(Widget);
        quitar->setObjectName(QString::fromUtf8("quitar"));

        gridLayout->addWidget(quitar, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        puerto = new QSpinBox(Widget);
        puerto->setObjectName(QString::fromUtf8("puerto"));
        puerto->setMaximum(9999999);

        horizontalLayout->addWidget(puerto);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        mensaje->setText(QApplication::translate("Widget", "Mensaje: ", nullptr));
        iniciar->setText(QApplication::translate("Widget", "Iniciar", nullptr));
        enviar->setText(QApplication::translate("Widget", "Enviar", nullptr));
        quitar->setText(QApplication::translate("Widget", "Quitar", nullptr));
        label->setText(QApplication::translate("Widget", "Puerto:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
