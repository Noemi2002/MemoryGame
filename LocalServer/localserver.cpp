#include "localserver.h"
#include <QTcpSocket>
#include <QTextStream>
#include "matriz.h"
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>


LocalServer::LocalServer(QObject *parent) : QTcpServer(parent)
{
    /*
     * Se abre el socket para la conexión del cliente
     */
    PtrServer = new QTcpServer(this);
    PtrServer->listen(QHostAddress::Any, 8080);
    PtrSocket = new QTcpSocket(this);

    connect(PtrServer, SIGNAL(newConnection()), this, SLOT(nuevaConexion()));
    iniciarJuego();
}


/*
 * Está atento a cuendo el cliente envía algún mensaje
 */
void LocalServer::nuevaConexion(){
    PtrSocket = PtrServer->nextPendingConnection();
    connect(PtrSocket, SIGNAL(readyRead()), this, SLOT(leerSocket()));
}


/*
 * Este método lee el mensaje del cliente, el nombre de la carta y la manda a buscar
 */
void LocalServer::leerSocket(){
    int aumento;
    QByteArray buffer;
    buffer.resize(PtrSocket->bytesAvailable());
    PtrSocket->read(buffer.data(), buffer.size());
    QString mensaje = QString(buffer);
    QString ct = Ptrmatriz->buscarImagenCarta(mensaje);

    if(!JuegoIniciado){
        carta1 = ct;
        carta2 = "";
        JuegoIniciado = true;
    }else{
        JuegoIniciado = false;
        carta2 = carta1;
        carta1 = ct;
        aumento = obtenerResultado(carta1, carta2);
    }
    aumento = obtenerResultado(carta1, carta2);
    enviar(ct, aumento);
}


/*
 * Envía la dirección de la imagen más los puntos que se obtuvieron.
 */
void LocalServer::enviar(QString mensaje, int puntos){
    QString nuevoMensaje = "url(/home/mimi/Documentos/Qt/MemoryGame/" + mensaje + ")" + ":" + QString::number(puntos);
    PtrSocket->write(nuevoMensaje.toLatin1().data(), nuevoMensaje.size());
}


/*
 * Verifica si las imagenes asignadas a las cartas on iguales, en este caso retorna un 5, en caso contrario, retorna un 0.
 */
int LocalServer::obtenerResultado(QString uno, QString dos){
    if (uno == dos){
        puntajeJugador1 += 5;
        return 5;
    }else{
        return 0;
    }
}


/*
 * En este método se inicializan las varibales importantes, se crea el puntero hacia la clase Matriz y se llama al método principal de esa clase.
 */
void LocalServer::iniciarJuego(){
    JuegoIniciado = false;
    puntajeJugador1 = 0;

    Ptrmatriz = new Matriz();
    Ptrmatriz->inicio();
}

