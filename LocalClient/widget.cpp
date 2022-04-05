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
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta02_clicked()
{
    std::string s = "carta02";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta03_clicked()
{
    std::string s = "carta03";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta04_clicked()
{
    std::string s = "carta04";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta05_clicked()
{
    std::string s = "carta05";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta06_clicked()
{
    std::string s = "carta06";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta07_clicked()
{
    std::string s = "carta07";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta08_clicked()
{
    std::string s = "carta08";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta09_clicked()
{
    std::string s = "carta09";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta10_clicked()
{
    std::string s = "carta10";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta11_clicked()
{
    std::string s = "carta11";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta12_clicked()
{
    std::string s = "carta12";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta13_clicked()
{
    std::string s = "carta13";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta14_clicked()
{
    std::string s = "carta14";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta15_clicked()
{
    std::string s = "carta15";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta16_clicked()
{
    std::string s = "carta16";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta17_clicked()
{
    std::string s = "carta17";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta18_clicked()
{
    std::string s = "carta18";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta19_clicked()
{
    std::string s = "carta19";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta20_clicked()
{
    std::string s = "carta20";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta21_clicked()
{
    std::string s = "carta21";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta22_clicked()
{
    std::string s = "carta22";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta23_clicked()
{
    std::string s = "carta23";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta24_clicked()
{
    std::string s = "carta24";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta25_clicked()
{
    std::string s = "carta25";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta26_clicked()
{
    std::string s = "carta26";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta27_clicked()
{
    std::string s = "carta27";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta28_clicked()
{
    std::string s = "carta28";
    obtenerNombreNumericoCarta(s);}

void Widget::on_carta29_clicked()
{
    std::string s = "carta29";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta30_clicked()
{
    std::string s = "carta30";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta31_clicked()
{
    std::string s = "carta31";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta32_clicked()
{
    std::string s = "carta32";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta33_clicked()
{
    std::string s = "carta33";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta34_clicked()
{   
    std::string s = "carta34";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta35_clicked()
{
    std::string s = "carta35";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta36_clicked()
{
    std::string s = "carta36";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta37_clicked()
{
    std::string s = "carta37";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta38_clicked()
{
    std::string s = "carta38";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta39_clicked()
{
    std::string s = "carta39";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta40_clicked()
{
    std::string s = "carta40";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta41_clicked()
{
    std::string s = "carta41";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta42_clicked()
{
    std::string s = "carta42";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta43_clicked()
{
    std::string s = "carta43";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta44_clicked()
{
    std::string s = "carta44";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta45_clicked()
{
    std::string s = "carta45";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta46_clicked()
{
    std::string s = "carta46";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta47_clicked()
{
    std::string s = "carta47";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta48_clicked()
{
    std::string s = "carta48";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta49_clicked()
{
    std::string s = "carta49";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta50_clicked()
{
    std::string s = "carta50";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta51_clicked()
{
    std::string s = "carta51";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta52_clicked()
{
    std::string s = "carta52";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta53_clicked()
{
    std::string s = "carta53";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta54_clicked()
{
    std::string s = "carta54";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta55_clicked()
{
    std::string s = "carta55";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta56_clicked()
{
    std::string s = "carta56";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta57_clicked()
{
    std::string s = "carta57";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta58_clicked()
{
    std::string s = "carta58";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta59_clicked()
{
    std::string s = "carta59";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta60_clicked()
{
    std::string s = "carta60";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta61_clicked()
{
    std::string s = "carta61";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta62_clicked()
{
    std::string s = "carta62";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta63_clicked()
{
    std::string s = "carta63";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta64_clicked()
{
    std::string s = "carta64";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta65_clicked()
{
    std::string s = "carta65";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta66_clicked()
{
    std::string s = "carta66";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta67_clicked()
{
    std::string s = "carta67";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta68_clicked()
{
    std::string s = "carta68";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta69_clicked()
{
    std::string s = "carta69";
    obtenerNombreNumericoCarta(s);
}

void Widget::on_carta70_clicked()
{
    std::string s = "carta70";
    obtenerNombreNumericoCarta(s);
}

void Widget::obtenerNombreNumericoCarta(std::string s){

    std::string delimiter = "carta";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
    }
    cortarNombre(QString::fromStdString(s));

}

void Widget::cortarNombre(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
    ui->TextEDit->appendPlainText(nombre);
    ui->Mensaje->clear();
}


