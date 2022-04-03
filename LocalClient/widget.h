#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void leer();

    void on_Enviar_clicked();
    void enviarNombreCarta(QString carta);



    void on_carta1_2_clicked();
    void on_carta2_2_clicked();
    void on_carta3_2_clicked();
    void on_carta4_2_clicked();
    void on_carta5_2_clicked();
    void on_carta6_2_clicked();
    void on_carta7_2_clicked();
    void on_carta8_2_clicked();
    void on_carta9_2_clicked();
    void on_carta10_2_clicked();
    void on_carta11_2_clicked();
    void on_carta12_2_clicked();
    void on_carta13_2_clicked();
    void on_carta14_2_clicked();
    void on_carta15_2_clicked();
    void on_carta16_2_clicked();
    void on_carta17_2_clicked();
    void on_carta18_2_clicked();
    void on_carta19_2_clicked();
    void on_carta20_2_clicked();
    void on_carta21_2_clicked();
    void on_carta22_2_clicked();
    void on_carta23_2_clicked();
    void on_carta24_2_clicked();
    void on_carta25_2_clicked();
    void on_carta26_2_clicked();
    void on_carta27_2_clicked();
    void on_carta28_2_clicked();
    void on_carta29_2_clicked();
    void on_carta30_2_clicked();
    void on_carta31_2_clicked();
    void on_carta32_2_clicked();
    void on_carta33_2_clicked();
    void on_carta34_2_clicked();
    void on_carta35_2_clicked();
    void on_carta36_2_clicked();
    void on_carta37_2_clicked();
    void on_carta38_2_clicked();
    void on_carta39_2_clicked();
    void on_carta40_2_clicked();
    void on_carta41_2_clicked();
    void on_carta42_2_clicked();
    void on_carta43_2_clicked();
    void on_carta44_2_clicked();
    void on_carta45_2_clicked();
    void on_carta46_2_clicked();
    void on_carta47_2_clicked();
    void on_carta48_2_clicked();
    void on_carta49_2_clicked();
    void on_carta50_2_clicked();
    void on_carta51_2_clicked();
    void on_carta52_2_clicked();
    void on_carta53_2_clicked();
    void on_carta54_2_clicked();
    void on_carta55_2_clicked();
    void on_carta56_2_clicked();
    void on_carta57_2_clicked();
    void on_carta58_2_clicked();
    void on_carta59_2_clicked();
    void on_carta60_2_clicked();
    void on_carta61_2_clicked();
    void on_carta62_2_clicked();
    void on_carta63_2_clicked();
    void on_carta64_2_clicked();
    void on_carta65_2_clicked();
    void on_carta66_2_clicked();
    void on_carta67_2_clicked();
    void on_carta68_2_clicked();
    void on_carta69_2_clicked();
    void on_carta70_2_clicked();


private:
    Ui::Widget *ui;
    QTcpSocket *PtrSocketC;
};
#endif // WIDGET_H



/*#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_conectar_clicked();
    void enviar();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
    MainWindow *g;
};
#endif // WIDGET_H*/
