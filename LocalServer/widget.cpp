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

    mezclarImagenes(NombreCartas);
    mezclarImagenes(NombreImagenes);
    //armarMatriz(NombreImagenes, matriz);
    //repartir(NombreCartas, reparto);
    puntajeJugador = 0;


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
    obtenerIndices(QString(buffer));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::obtenerIndices(QString carta){
    int valor = carta.toInt();

    i = (valor/10)%10 + 1;
    if (valor % 10 == 0){
        i -= 1;
    }
    j = valor%10;
    if (j == 0){
        j = 10;
    }

}

void Widget::on_Enviar_clicked()
{

    PtrSocket->write(ui->mensaje->text().toLatin1().data(), ui->mensaje->text().size());
    ui->texto->appendPlainText(ui->mensaje->text());
    ui->mensaje->clear();
}

void Widget::mezclarImagenes(QVector<QString> &NombreImagenes){
    unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(NombreImagenes.begin(), NombreImagenes.end(), std::default_random_engine(semilla)); //default_random_engine(semilla) es el generador de los números aleatorios
}

void Widget::repartir(QVector<QString> &NombreCartas, QHash<QString, QString> &reparto){
    auto iterador=NombreCartas.begin();
    for (int i=1; i<=6; i++){
        QString file_name="0"+QString::number(i)+".png";
        reparto[(*iterador)]=file_name;
        iterador++;
        reparto[(*iterador)]=file_name;
        iterador++;
    }
}

/*void Widget::armarMatriz(QVector<QString> &NombreImagenes, QString &matriz){
    auto iterador = NombreImagenes.begin();
    for (int i=0; i<7; i++){
        for (int j=0; i<10; j++){
            matriz[i][j] = &iterador;
            iterador++;
        }
    }
}*/
