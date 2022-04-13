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
    /*PtrSocketC->write(ui->Mensaje->text().toLatin1().data(), ui->Mensaje->text().size());
    ui->TextEDit->appendPlainText(ui->Mensaje->text());
    ui->Mensaje->clear();*/

    PtrSocketC->write(ui->Enviar->objectName().toLatin1().data(), ui->Enviar->objectName().size());
    ui->TextEDit->appendPlainText(ui->Enviar->objectName());
    ui->Mensaje->clear();

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

void Widget::on_carta31_clicked()
{
    std::string s = "carta31";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta32_clicked()
{
    std::string s = "carta32";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta33_clicked()
{
    std::string s = "carta33";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta34_clicked()
{   
    std::string s = "carta34";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta35_clicked()
{
    std::string s = "carta35";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta36_clicked()
{
    std::string s = "carta36";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta37_clicked()
{
    std::string s = "carta37";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta38_clicked()
{
    std::string s = "carta38";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta39_clicked()
{
    std::string s = "carta39";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta40_clicked()
{
    std::string s = "carta40";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta41_clicked()
{
    std::string s = "carta41";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta42_clicked()
{
    std::string s = "carta42";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta43_clicked()
{
    std::string s = "carta43";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta44_clicked()
{
    std::string s = "carta44";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta45_clicked()
{
    std::string s = "carta45";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta46_clicked()
{
    std::string s = "carta46";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta47_clicked()
{
    std::string s = "carta47";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta48_clicked()
{
    std::string s = "carta48";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta49_clicked()
{
    std::string s = "carta49";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta50_clicked()
{
    std::string s = "carta50";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta51_clicked()
{
    std::string s = "carta51";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta52_clicked()
{
    std::string s = "carta52";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta53_clicked()
{
    std::string s = "carta53";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta54_clicked()
{
    std::string s = "carta54";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta55_clicked()
{
    std::string s = "carta55";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta56_clicked()
{
    std::string s = "carta56";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta57_clicked()
{
    std::string s = "carta57";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta58_clicked()
{
    std::string s = "carta58";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta59_clicked()
{
    std::string s = "carta59";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta60_clicked()
{
    std::string s = "carta60";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta61_clicked()
{
    std::string s = "carta61";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta62_clicked()
{
    std::string s = "carta62";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta63_clicked()
{
    std::string s = "carta63";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta64_clicked()
{
    std::string s = "carta64";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta65_clicked()
{
    std::string s = "carta65";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta66_clicked()
{
    std::string s = "carta66";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta67_clicked()
{
    std::string s = "carta67";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta68_clicked()
{
    std::string s = "carta68";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta69_clicked()
{
    std::string s = "carta69";
    EnviarCarta(QString::fromStdString(s));
}

void Widget::on_carta70_clicked()
{
    QString s = "carta70";
    EnviarCarta(s);
}

void Widget::obtenerNombreNumericoCarta(std::string s){

    std::string delimiter = "carta";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
    }
    EnviarCarta(QString::fromStdString(s));

}

void Widget::EnviarCarta(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
    ui->TextEDit->appendPlainText(nombre);
    ui->Mensaje->clear();
}


