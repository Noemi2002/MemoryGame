#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMatrix>
#include<QVector>
#include <QHash>
#include<QString>
#include <random>
#include <QMatrix>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QVector<QString> NombreCartas{"carta1_2","carta2_2","carta3_2","carta4_2","carta5_2","carta6_2","carta7_2",
                                   "carta8_2","carta9_2","carta10_2","carta11_2","carta12_2","carta13_2","carta14_2",
                                   "carta15_2","carta16_2","carta17_2","carta18_2","carta19_2","carta20_2","carta21_2",
                                    "carta22_2","carta23_2","carta24_2","carta25_2","carta26_2","carta27_2","carta28_2",
                                    "carta29_2","carta30_2","carta31_2","carta32_2","carta33_2","carta34_2","carta35_2",
                                    "carta36_2","carta37_2","carta38_2","carta39_2","carta40_2","carta41_2","carta42_2",
                                    "carta43_2","carta44_2","carta45_2""carta46_2","carta47_2","carta48_2","carta49_2",
                                    "carta50_2","carta51_2","carta52_2","carta53_2","carta54_2","carta55_2","carta56_2",
                                    "carta57_2","carta58_2","carta59_2","carta60_2","carta61_2","carta62_2","carta63_2",
                                    "carta64_2","carta65_2","carta66_2","carta67_2","carta68_2","carta69_2","carta70_2"};

    QVector<QString> NombreImagenes{"1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png" ,"10.png" ,""
                                    "11.png" ,"12.png" ,"13.png", "14.png", "15.png", "16.png", "17.png", "18.png", "19.png", "20.png",
                                    "21.png", "22.png", "23.png", "24.png", "25.png" ,"26.png" ,"27.png" ,"28.png" ,"29.png",
                                    "30.png", "31.png", "32.png", "33.png", "34.png", "35.png",
                                    "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png" ,"10.png" ,
                                    "11.png" ,"12.png" ,"13.png", "14.png", "15.png", "16.png", "17.png", "18.png", "19.png", "20.png",
                                    "21.png", "22.png", "23.png", "24.png", "25.png" ,"26.png" ,"27.png" ,"28.png" ,"29.png",
                                    "30.png", "31.png", "32.png", "33.png", "34.png", "35.png"};
     QHash<QString, QString> reparto;



    QString matriz[7][10];
    int puntajeJugador;
    int i;
    int j;


private slots:
    void nuevaConexion();
    void leerSocket();
    void mezclarImagenes(QVector<QString> &NombreImagenes);
    //void armarMatriz(QVector<QString> &NombreImagenes, QString &matriz);
    //void buscarEnMtriz( QString &matriz);
    void repartir(QVector<QString> &NombreImagenes, QHash<QString, QString> &reparto);
    void obtenerIndices(QString carta);


    void on_Enviar_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *PtrServer;
    QTcpSocket *PtrSocket;
    QString *PtrMatriz;
};
#endif // WIDGET_H







