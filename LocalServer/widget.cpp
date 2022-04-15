#include "widget.h"
#include "ui_widget.h"
#include "matrizDisco.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    PtrServer = new QTcpServer(this);
    PtrServer->listen(QHostAddress::Any, 8080);
    PtrSocket = new QTcpSocket(this);

    connect(PtrServer, SIGNAL(newConnection()), this, SLOT(nuevaConexion()));
    iniciarJuego();
}

void Widget::nuevaConexion(){
    PtrSocket = PtrServer->nextPendingConnection();
    connect(PtrSocket, SIGNAL(readyRead()), this, SLOT(leerSocket()));
}

void Widget::leerSocket(){

    QByteArray buffer;
    buffer.resize(PtrSocket->bytesAvailable());
    PtrSocket->read(buffer.data(), buffer.size());
    ui->texto->setReadOnly(true);
    QString mensaje = QString(buffer);
    ui->texto->appendPlainText(mensaje);
    QString idea = Ptrmatriz->buscarImagenCarta(mensaje);
    ui->texto->appendPlainText(idea);
}

Widget::~Widget()
{ delete ui;}

void Widget::on_Enviar_clicked()
{
    PtrSocket->write(ui->mensaje->text().toLatin1().data(), ui->mensaje->text().size());
    ui->texto->appendPlainText(ui->mensaje->text());
    ui->mensaje->clear();
}

/*void Widget::pedirImagen(QString carta){
    QString imagen = Ptrmatriz->buscarImagenCarta(fila, columna, carta);
    ui->texto->setReadOnly(true);
    ui->texto->appendPlainText(imagen);
}*/


void Widget::iniciarJuego(){
    Ptrmatriz = new Matriz();
    auto ListaCartas = Ptrmatriz->NombreCartas;
    auto TablaHash = Ptrmatriz->TablasHash;
    auto MatrizActual = Ptrmatriz->MatrizActual;
    Ptrmatriz->mezclarImagenes(ListaCartas);

    Ptrmatriz->MatrizDisco(ListaCartas, TablaHash);
    Ptrmatriz->crearMatrizMemoria(ListaCartas, TablaHash);
    Ptrmatriz->EscribirMartriz("matriz.txt", TablaHash, ListaCartas);
    Ptrmatriz->EscribirMartriz("matriz2.txt", MatrizActual, ListaCartas);

}


