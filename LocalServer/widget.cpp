#include "widget.h"
#include "ui_widget.h"
#include "matrizDisco.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Ptrmatriz = new Matriz();
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


    int numero = Ptrmatriz->obtenerNombreNumericoCarta(mensaje);
    int i = Ptrmatriz->obtenerIndicesi(numero);
    int j = Ptrmatriz->obtenerIndicesj(numero);
    ui->texto->appendPlainText("Fila: "+ QString::number(i));
    ui->texto->appendPlainText("Columna: "+ QString::number(j));
}

Widget::~Widget()
{ delete ui;}

void Widget::on_Enviar_clicked()
{
    PtrSocket->write(ui->mensaje->text().toLatin1().data(), ui->mensaje->text().size());
    ui->texto->appendPlainText(ui->mensaje->text());
    ui->mensaje->clear();
}

/*void Widget::paginacion(QString filename, QString elegida, int max){
 *
    QTextStream stream(&filename);
    ifstream archivo("matriz.txt");;

    int contador=0;
    while(getline(archivo, elegida)){
        QString line = stream.readLine();
        if(max == contador){
        ui->texto->appendPlainText(elegida);}
        contador++;
    }
}*/

void Widget::encontrarImagen(QHash<QString, QString> &MatrizActual, QString carta)
{
    ui->texto->setReadOnly(true);
    if(MatrizActual[carta] == NULL){
        //ui->texto->appendPlainText(QString(MatrizActual[carta]));
        //paginacion("matriz.txt", carta, 1);
        ui->texto->appendPlainText(QString("Se debe cargar la imagen"));
        //QString imagenCorrespondiente = MatrizActual[carta];
    }else{

        ui->texto->appendPlainText(QString(MatrizActual[carta]));
   }
}

void Widget::iniciarJuego(){

    auto ListaCartas = Ptrmatriz->NombreCartas;
    auto TablaHash = Ptrmatriz->TablasHash;
    auto MatrizActual = Ptrmatriz->MatrizActual;
    Ptrmatriz->mezclarImagenes(ListaCartas);

    Ptrmatriz->MatrizDisco(ListaCartas, TablaHash);
    Ptrmatriz->crearMatrizMemoria(ListaCartas, TablaHash);
    Ptrmatriz->EscribirMartriz("matriz.txt", TablaHash, ListaCartas);
    Ptrmatriz->EscribirMartriz("matriz2.txt", MatrizActual, ListaCartas);
}


