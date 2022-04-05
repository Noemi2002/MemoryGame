#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTimer *PtrTiempo=new QTimer();
    QTime tiempo;
    int parejasRestantes = 35;

private slots:
    void leer();

    void on_Enviar_clicked();
    void iniciarJuego();
    void cronometro();
    void finalizarJuego();
    void cortarNombre(QString nombre);
    void obtenerNombreNumericoCarta(std::string s);




    void on_carta01_clicked();
    void on_carta02_clicked();
    void on_carta03_clicked();
    void on_carta04_clicked();
    void on_carta05_clicked();
    void on_carta06_clicked();
    void on_carta07_clicked();
    void on_carta08_clicked();
    void on_carta09_clicked();
    void on_carta10_clicked();
    void on_carta11_clicked();
    void on_carta12_clicked();
    void on_carta13_clicked();
    void on_carta14_clicked();
    void on_carta15_clicked();
    void on_carta16_clicked();
    void on_carta17_clicked();
    void on_carta18_clicked();
    void on_carta19_clicked();
    void on_carta20_clicked();
    void on_carta21_clicked();
    void on_carta22_clicked();
    void on_carta23_clicked();
    void on_carta24_clicked();
    void on_carta25_clicked();
    void on_carta26_clicked();
    void on_carta27_clicked();
    void on_carta28_clicked();
    void on_carta29_clicked();
    void on_carta30_clicked();
    void on_carta31_clicked();
    void on_carta32_clicked();
    void on_carta33_clicked();
    void on_carta34_clicked();
    void on_carta35_clicked();
    void on_carta36_clicked();
    void on_carta37_clicked();
    void on_carta38_clicked();
    void on_carta39_clicked();
    void on_carta40_clicked();
    void on_carta41_clicked();
    void on_carta42_clicked();
    void on_carta43_clicked();
    void on_carta44_clicked();
    void on_carta45_clicked();
    void on_carta46_clicked();
    void on_carta47_clicked();
    void on_carta48_clicked();
    void on_carta49_clicked();
    void on_carta50_clicked();
    void on_carta51_clicked();
    void on_carta52_clicked();
    void on_carta53_clicked();
    void on_carta54_clicked();
    void on_carta55_clicked();
    void on_carta56_clicked();
    void on_carta57_clicked();
    void on_carta58_clicked();
    void on_carta59_clicked();
    void on_carta60_clicked();
    void on_carta61_clicked();
    void on_carta62_clicked();
    void on_carta63_clicked();
    void on_carta64_clicked();
    void on_carta65_clicked();
    void on_carta66_clicked();
    void on_carta67_clicked();
    void on_carta68_clicked();
    void on_carta69_clicked();
    void on_carta70_clicked();


private:
    Ui::Widget *ui;
    QTcpSocket *PtrSocketC;
};
#endif // WIDGET_H

