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

    mezclarNombresCartas(NombreCartas);
    repartirImagenes(NombreCartas, reparto);

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

void Widget::mezclarNombresCartas(QVector<QString> &NombreCartas){
    unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(NombreCartas.begin(), NombreCartas.end(), std::default_random_engine(semilla)); //default_random_engine(semilla) es el generador de los números aleatorios
}

QString Widget::repartirImagenes(QVector<QString> &NombreCartas, QHash<QString, QString> &reparto){
    auto iterador = NombreCartas.begin();
    for (int i=0; i<35; i++){
        QString file_name = QString::number(i)+".png";
        reparto[(*iterador)] = file_name;
        iterador++;
        reparto[(*iterador)] = file_name;
        iterador++;
    }

}


