#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    PtrServer = new QTcpServer(this);
    PtrServer->listen(QHostAddress::Any, 8080);
    PtrSocket = new QTcpSocket(this);

    connect(PtrServer, SIGNAL(newConnection()), this, SLOT(nuevaConexion()));
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
    ui->texto->appendPlainText(QString(buffer));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Enviar_clicked()
{

    PtrSocket->write(ui->mensaje->text().toLatin1().data(), ui->mensaje->text().size());
    ui->texto->appendPlainText(ui->mensaje->text());
    ui->mensaje->clear();
}


/*#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>
#include <QTextStream>
#include <QTcpSocket>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new LocalServer(this);
    PtrComunicacion = new QTcpSocket(this);
    connect(PtrComunicacion, &QTcpSocket::readyRead, [&](){
       QTextStream T(PtrComunicacion);
       ui->MensajeDeCLiente->addItem(T.readAll());
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
   if (!mLocalServer->listen(QHostAddress::LocalHost, 8080)){
        QMessageBox::critical(this, "Error", mLocalServer->errorString());
   }else{
   QMessageBox::information(this, "Servidor", "Iniciado...");
   //mLocalServer->mezclarNombresVector();
   //mLocalServer->repartirImagenes();
   }
}

/*void Widget::on_enviar_clicked()
{

    mLocalServer->envia(ui->msj->text());
}

void Widget::on_quitar_clicked()
{
    close();
}*/



