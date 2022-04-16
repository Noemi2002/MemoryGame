#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    PtrSocketC = new QTcpSocket(this);
    PtrSocketC->connectToHost("localhost", 8080);

    if(PtrSocketC->waitForConnected(3000)){
        QMessageBox::information(this, "Excelente", "Se conectó al servidor correctamente");
    }else{
        QMessageBox::critical(this, "ERROR", "No se pudo conectar al servidor");

    }
    connect(PtrSocketC, SIGNAL(readyRead()), this, SLOT(leer()));
    connect(PtrTiempo, SIGNAL(timeout()), this, SLOT(cronometro()));
    //connect(ui->carta02, SIGNAL(clicked(bool)), this, SLOT(pruebaEnviarNombre(ui->carta02->objectName());));
    iniciarJuego();



}

void Widget::iniciarJuego(){

    tiempo.setHMS(0,0,0);
    ui->cronometro->setText(tiempo.toString("m:ss"));
    PtrTiempo->start(1000);

}

void Widget::cronometro(){
        tiempo=tiempo.addSecs(1);
        ui->cronometro->setText(tiempo.toString("m:ss"));

}


void Widget::leer(){
    QByteArray buffer;
    buffer.resize(PtrSocketC->bytesAvailable());
    PtrSocketC->read(buffer.data(), buffer.size());
    ui->TextEDit->setReadOnly(true);
    ui->TextEDit->appendPlainText(QString(buffer));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::finalizarJuego(){


    if(parejasRestantes == 0){
        PtrTiempo->stop();
        QMessageBox::information(this, "Se acabó el juego", "¡Felicidades!, has ganado");
    }else{
        if (tiempo.toString()=="00:15:00" && parejasRestantes != 0){
            PtrTiempo->stop();
            QMessageBox::information(this, "Se acabó el juego", "¡Lo siento!, has perdido");
        }
    }
}

void Widget::on_Enviar_clicked(){
    PtrSocketC->write(ui->Mensaje->text().toLatin1().data(), ui->Mensaje->text().size());
    ui->TextEDit->appendPlainText(ui->Mensaje->text());
    ui->Mensaje->clear();

    /*PtrSocketC->write(ui->Enviar->objectName().toLatin1().data(), ui->Enviar->objectName().size());
    ui->TextEDit->appendPlainText(ui->Enviar->objectName());
    ui->Mensaje->clear();*/

}

//Funciones de las tarjetas

void Widget::on_carta01_clicked()
{
    std::string s = "carta01";
    //obtenerNombreNumericoCarta(s);
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta02_clicked()
{
    std::string s = "carta02";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta03_clicked()
{
    std::string s = "carta03";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta04_clicked()
{
    std::string s = "carta04";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta05_clicked()
{
    std::string s = "carta05";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta06_clicked()
{
    std::string s = "carta06";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta07_clicked()
{
    std::string s = "carta07";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta08_clicked()
{
    std::string s = "carta08";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta09_clicked()
{
    std::string s = "carta09";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta10_clicked()
{
    std::string s = "carta10";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta11_clicked()
{
    std::string s = "carta11";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta12_clicked()
{
    std::string s = "carta12";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta13_clicked()
{
    std::string s = "carta13";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta14_clicked()
{
    std::string s = "carta14";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta15_clicked()
{
    std::string s = "carta15";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta16_clicked()
{
    std::string s = "carta16";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta17_clicked()
{
    std::string s = "carta17";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta18_clicked()
{
    std::string s = "carta18";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta19_clicked()
{
    std::string s = "carta19";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta20_clicked()
{
    std::string s = "carta20";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta21_clicked()
{
    std::string s = "carta21";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta22_clicked()
{
    std::string s = "carta22";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta23_clicked()
{
    std::string s = "carta23";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta24_clicked()
{
    std::string s = "carta24";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta25_clicked()
{
    std::string s = "carta25";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta26_clicked()
{
    std::string s = "carta26";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta27_clicked()
{
    std::string s = "carta27";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta28_clicked()
{
    std::string s = "carta28";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta29_clicked()
{
    std::string s = "carta29";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta30_clicked()
{
    std::string s = "carta30";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::EnviarCarta(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
    ui->TextEDit->appendPlainText(nombre);
    ui->Mensaje->clear();
}


