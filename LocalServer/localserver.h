#ifndef LOCALSERVER_H
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
    QVector<QString> NombreTarjetas{"carta1","carta2","carta3","carta4","carta5","carta6","carta7",
                                   "carta8","carta9","carta10","carta11","carta12","carta13","carta14",
                                   "carta15","carta16","carta17","carta18","carta19","carta20","carta21",
                                    "carta22","carta23","carta24","carta25","carta26","carta27","carta28",
                                    "carta29","carta30","carta31","carta32","carta33","carta34","carta35",
                                    "carta36","carta37","carta38","carta39","carta40","carta41","carta42",
                                    "carta43","carta44","carta45""carta46","carta47","carta48","carta49",
                                    "carta50","carta51","carta52","carta53","carta54","carta55","carta56",
                                    "carta57","carta58","carta59","carta60","carta61","carta62","carta63",
                                    "carta64","carta65","carta66","carta67","carta68","carta69","carta70"};
    QHash<QString, QString> reparto;
    int puntajeJugador1;
    int puntajeJugador2;
    void mezclarNombresVector();
    void repartirImagenes();


private:
    QTcpSocket *mSocket;
    QString *matriz;

};

#endif
