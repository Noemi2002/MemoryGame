/*#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QTcpServer>
#include<random>
#include<QHash>

class QTcpSocket;

class LocalServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = 0);
    //QString crear_matriz[7][10];
    bool JuegoIniciado;
    QVector<QString> NombreTarjetas{"carta1_2","carta2_2","carta3_2","carta4_2","carta5_2","carta6_2","carta7_2",
                                   "carta8_2","carta9_2","carta10_2","carta11_2","carta12_2","carta13_2","carta14_2",
                                   "carta15_2","carta16_2","carta17_2","carta18_2","carta19_2","carta20_2","carta21_2",
                                    "carta22_2","carta23_2","carta24_2","carta25_2","carta26_2","carta27_2","carta28_2",
                                    "carta29_2","carta30_2","carta31_2","carta32_2","carta33_2","carta34_2","carta35_2",
                                    "carta36_2","carta37_2","carta38_2","carta39_2","carta40_2","carta41_2","carta42_2",
                                    "carta43_2","carta44_2","carta45_2""carta46_2","carta47_2","carta48_2","carta49_2",
                                    "carta50_2","carta51_2","carta52_2","carta53_2","carta54_2","carta55_2","carta56_2",
                                    "carta57_2","carta58_2","carta59_2","carta60_2","carta61_2","carta62_2","carta63_2",
                                    "carta64_2","carta65_2","carta66_2","carta67_2","carta68_2","carta69_2","carta70_2"};
    /*QHash<QString, QString> reparto;
    int puntajeJugador1;
    int puntajeJugador2;
    void mezclarNombresVector();
    void repartirImagenes();


private:
    QTcpSocket *mSocket;
    //QString *matriz;

};

#endif //LOCALSERVER_H*/
