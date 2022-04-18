#include "localserver.h"
#include <QTcpSocket>
#include <QTextStream>
#include "matrizDisco.h"
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>


LocalServer::LocalServer(QObject *parent, Ui::Widget *ptr) : QTcpServer(parent)
{

    ptrUso = ptr;
    PtrServer = new QTcpServer(this);
    PtrServer->listen(QHostAddress::Any, 8080);
    PtrSocket = new QTcpSocket(this);

    connect(PtrServer, SIGNAL(newConnection()), this, SLOT(nuevaConexion()));
    iniciarJuego();

}

void LocalServer::nuevaConexion(){
    PtrSocket = PtrServer->nextPendingConnection();
    connect(PtrSocket, SIGNAL(readyRead()), this, SLOT(leerSocket()));
}

void LocalServer::leerSocket(){

    QByteArray buffer;
    buffer.resize(PtrSocket->bytesAvailable());
    PtrSocket->read(buffer.data(), buffer.size());
    QString mensaje = QString(buffer);
    QString idea = Ptrmatriz->buscarImagenCarta(mensaje);
    QString loquesea = QString(idea);
    enviar(loquesea);
    if(JuegoIniciado){
        carta1 = idea;
    }else{
        carta2 = carta1;
        carta1 = idea;
        obtenerResultado(carta1, carta2);
    }
    ptrUso->texto->setReadOnly(true);
    ptrUso->texto->appendPlainText(mensaje);
    ptrUso->texto->appendPlainText(loquesea);
}

void LocalServer::enviar(QString mensaje){
    PtrSocket->write(mensaje.toLatin1().data(), mensaje.size());
}

/*void Widget::pedirImagen(QString carta){
    QString imagen = Ptrmatriz->buscarImagenCarta(fila, columna, carta);
    ui->texto->setReadOnly(true);
    ui->texto->appendPlainText(imagen);
}*/

void LocalServer::obtenerResultado(QString uno, QString dos){
    if (uno == dos){
        puntajeJugador1 += 5;
    }

}

void LocalServer::iniciarJuego(){

    Ptrmatriz = new Matriz();
    Ptrmatriz->inicio();
    /*auto ListaCartas = Ptrmatriz->NombreCartas;
    auto TablaHash = Ptrmatriz->TablasHash;
    Ptrmatriz->mezclarImagenes(ListaCartas);

    Ptrmatriz->MatrizDisco(ListaCartas, TablaHash);
    Ptrmatriz->crearMatrizMemoria(ListaCartas, TablaHash);
    Ptrmatriz->EscribirMartriz("matriz.txt", TablaHash, ListaCartas);*/

}

