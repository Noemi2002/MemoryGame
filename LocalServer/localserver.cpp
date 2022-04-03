/*#include "localserver.h"
#include <QTcpSocket>
#include <QTextStream>


LocalServer::LocalServer(QObject *parent) : QTcpServer(parent)
{

    mSocket = nullptr;
    connect(this, &LocalServer::newConnection, [&](){
        mSocket = nextPendingConnection();
    });

}

/*void LocalServer::mezclarNombresVector(){
    unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(NombreTarjetas.begin(), NombreTarjetas.end(), std::default_random_engine(semilla)); //default_random_engine(semilla) es el generador de los números aleatorios
}

void LocalServer::repartirImagenes(){
    auto cabeza = NombreTarjetas.begin();
    for(int i=1; 1<=35; i++){
        QString file_name = QString::number(i)+".png";
        reparto[(*cabeza)] = file_name;
        cabeza++;
        reparto[(*cabeza)] = file_name;
        cabeza++;

    }
}*/

/*void LocalServer::envia(const QString &msj){

    if (mSocket){
    QTextStream T(mSocket);
    T << msj;
    mSocket->flush(); //limpiar el socket
    }
}*/
