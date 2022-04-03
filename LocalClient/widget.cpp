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

    //QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    //QString buttonText = buttonSender->text(); // retrive the text from the button clicked


    //connect(ui->carta2_2, SIGNAL(clicked()), this, SLOT(enviarNombreCarta("carta2_2")));
}

void Widget::enviarNombreCarta(QString carta){

    PtrSocketC->write(carta.toLatin1().data(), carta.size());
    ui->TextEDit->appendPlainText(carta);
    ui->Mensaje->clear();

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

void Widget::on_Enviar_clicked(){
    /*PtrSocketC->write(ui->Mensaje->text().toLatin1().data(), ui->Mensaje->text().size());
    ui->TextEDit->appendPlainText(ui->Mensaje->text());
    ui->Mensaje->clear();*/

    PtrSocketC->write(ui->Enviar->objectName().toLatin1().data(), ui->Enviar->objectName().size());
    ui->TextEDit->appendPlainText(ui->Enviar->objectName());
    ui->Mensaje->clear();

}

//Funciones de las tarjetas

void Widget::on_carta1_2_clicked()
{
    PtrSocketC->write(ui->carta1_2->objectName().toLatin1().data(), ui->carta1_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta1_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta2_2_clicked()
{
    PtrSocketC->write(ui->carta2_2->objectName().toLatin1().data(), ui->carta2_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta2_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta3_2_clicked()
{
    PtrSocketC->write(ui->carta3_2->objectName().toLatin1().data(), ui->carta3_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta3_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta4_2_clicked()
{
    PtrSocketC->write(ui->carta4_2->objectName().toLatin1().data(), ui->carta4_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta4_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta5_2_clicked()
{
    PtrSocketC->write(ui->carta5_2->objectName().toLatin1().data(), ui->carta5_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta5_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta6_2_clicked()
{
    PtrSocketC->write(ui->carta6_2->objectName().toLatin1().data(), ui->carta6_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta6_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta7_2_clicked()
{
    PtrSocketC->write(ui->carta7_2->objectName().toLatin1().data(), ui->carta7_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta7_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta8_2_clicked()
{
    PtrSocketC->write(ui->carta8_2->objectName().toLatin1().data(), ui->carta8_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta8_2->objectName());
    ui->Mensaje->clear();
}

void Widget::on_carta9_2_clicked()
{
    PtrSocketC->write(ui->carta9_2->objectName().toLatin1().data(), ui->carta9_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta9_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta10_2_clicked()
{
    PtrSocketC->write(ui->carta10_2->objectName().toLatin1().data(), ui->carta10_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta10_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta11_2_clicked()
{
    PtrSocketC->write(ui->carta11_2->objectName().toLatin1().data(), ui->carta11_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta11_2->objectName());
    ui->Mensaje->clear();
}

void Widget::on_carta12_2_clicked()
{
    PtrSocketC->write(ui->carta12_2->objectName().toLatin1().data(), ui->carta12_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta12_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta13_2_clicked()
{
    PtrSocketC->write(ui->carta13_2->objectName().toLatin1().data(), ui->carta13_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta13_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta14_2_clicked()
{
    PtrSocketC->write(ui->carta14_2->objectName().toLatin1().data(), ui->carta14_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta14_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta15_2_clicked()
{
    PtrSocketC->write(ui->carta15_2->objectName().toLatin1().data(), ui->carta15_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta15_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta16_2_clicked()
{
    PtrSocketC->write(ui->carta16_2->objectName().toLatin1().data(), ui->carta16_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta16_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta17_2_clicked()
{
    PtrSocketC->write(ui->carta17_2->objectName().toLatin1().data(), ui->carta17_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta17_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta18_2_clicked()
{
    PtrSocketC->write(ui->carta18_2->objectName().toLatin1().data(), ui->carta18_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta18_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta19_2_clicked()
{
    PtrSocketC->write(ui->carta19_2->objectName().toLatin1().data(), ui->carta19_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta19_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta20_2_clicked()
{
    PtrSocketC->write(ui->carta20_2->objectName().toLatin1().data(), ui->carta20_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta20_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta21_2_clicked()
{

    PtrSocketC->write(ui->carta21_2->objectName().toLatin1().data(), ui->carta21_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta21_2->objectName());
    //ui->Mensaje->clear();

}

void Widget::on_carta22_2_clicked()
{
    PtrSocketC->write(ui->carta22_2->objectName().toLatin1().data(), ui->carta22_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta22_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta23_2_clicked()
{
    PtrSocketC->write(ui->carta23_2->objectName().toLatin1().data(), ui->carta23_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta23_2->objectName());
    ui->Mensaje->clear();
}

void Widget::on_carta24_2_clicked()
{

    PtrSocketC->write(ui->carta24_2->objectName().toLatin1().data(), ui->carta24_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta24_2->objectName());
    //ui->Mensaje->clear();

}

void Widget::on_carta25_2_clicked()
{
    PtrSocketC->write(ui->carta25_2->objectName().toLatin1().data(), ui->carta25_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta25_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta26_2_clicked()
{
    PtrSocketC->write(ui->carta26_2->objectName().toLatin1().data(), ui->carta26_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta26_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta27_2_clicked()
{
    PtrSocketC->write(ui->carta27_2->objectName().toLatin1().data(), ui->carta27_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta27_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta28_2_clicked()
{
    PtrSocketC->write(ui->carta28_2->objectName().toLatin1().data(), ui->carta28_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta28_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta29_2_clicked()
{
    PtrSocketC->write(ui->carta29_2->objectName().toLatin1().data(), ui->carta29_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta29_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta30_2_clicked()
{
    PtrSocketC->write(ui->carta30_2->objectName().toLatin1().data(), ui->carta30_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta30_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta31_2_clicked()
{
    PtrSocketC->write(ui->carta31_2->objectName().toLatin1().data(), ui->carta31_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta31_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta32_2_clicked()
{
    PtrSocketC->write(ui->carta32_2->objectName().toLatin1().data(), ui->carta32_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta32_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta33_2_clicked()
{
    PtrSocketC->write(ui->carta33_2->objectName().toLatin1().data(), ui->carta33_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta33_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta34_2_clicked()
{
    PtrSocketC->write(ui->carta34_2->objectName().toLatin1().data(), ui->carta34_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta34_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta35_2_clicked()
{
    PtrSocketC->write(ui->carta35_2->objectName().toLatin1().data(), ui->carta35_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta35_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta36_2_clicked()
{
    PtrSocketC->write(ui->carta36_2->objectName().toLatin1().data(), ui->carta36_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta36_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta37_2_clicked()
{
    PtrSocketC->write(ui->carta37_2->objectName().toLatin1().data(), ui->carta37_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta37_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta38_2_clicked()
{
    PtrSocketC->write(ui->carta38_2->objectName().toLatin1().data(), ui->carta38_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta38_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta39_2_clicked()
{
    PtrSocketC->write(ui->carta39_2->objectName().toLatin1().data(), ui->carta39_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta39_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta40_2_clicked()
{
    PtrSocketC->write(ui->carta40_2->objectName().toLatin1().data(), ui->carta40_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta40_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta41_2_clicked()
{
    PtrSocketC->write(ui->carta41_2->objectName().toLatin1().data(), ui->carta41_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta41_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta42_2_clicked()
{
    PtrSocketC->write(ui->carta42_2->objectName().toLatin1().data(), ui->carta42_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta42_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta43_2_clicked()
{
    PtrSocketC->write(ui->carta43_2->objectName().toLatin1().data(), ui->carta43_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta43_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta44_2_clicked()
{
    PtrSocketC->write(ui->carta44_2->objectName().toLatin1().data(), ui->carta44_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta44_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta45_2_clicked()
{
    PtrSocketC->write(ui->carta45_2->objectName().toLatin1().data(), ui->carta45_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta45_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta46_2_clicked()
{
    PtrSocketC->write(ui->carta46_2->objectName().toLatin1().data(), ui->carta46_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta46_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta47_2_clicked()
{
    PtrSocketC->write(ui->carta47_2->objectName().toLatin1().data(), ui->carta47_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta47_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta48_2_clicked()
{
    PtrSocketC->write(ui->carta48_2->objectName().toLatin1().data(), ui->carta48_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta48_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta49_2_clicked()
{
    PtrSocketC->write(ui->carta49_2->objectName().toLatin1().data(), ui->carta49_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta49_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta50_2_clicked()
{
    PtrSocketC->write(ui->carta50_2->objectName().toLatin1().data(), ui->carta50_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta50_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta51_2_clicked()
{

    PtrSocketC->write(ui->carta51_2->objectName().toLatin1().data(), ui->carta51_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta51_2->objectName());
    //ui->Mensaje->clear();

}

void Widget::on_carta52_2_clicked()
{
    PtrSocketC->write(ui->carta52_2->objectName().toLatin1().data(), ui->carta52_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta52_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta53_2_clicked()
{
    PtrSocketC->write(ui->carta53_2->objectName().toLatin1().data(), ui->carta53_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta53_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta54_2_clicked()
{

    PtrSocketC->write(ui->carta54_2->objectName().toLatin1().data(), ui->carta54_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta54_2->objectName());
    //ui->Mensaje->clear();

}

void Widget::on_carta55_2_clicked()
{
    PtrSocketC->write(ui->carta55_2->objectName().toLatin1().data(), ui->carta55_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta55_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta56_2_clicked()
{
    PtrSocketC->write(ui->carta56_2->objectName().toLatin1().data(), ui->carta56_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta56_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta57_2_clicked()
{
    PtrSocketC->write(ui->carta57_2->objectName().toLatin1().data(), ui->carta57_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta57_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta58_2_clicked()
{
    PtrSocketC->write(ui->carta58_2->objectName().toLatin1().data(), ui->carta58_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta58_2->objectName());
    ui->Mensaje->clear();
}

void Widget::on_carta59_2_clicked()
{
    PtrSocketC->write(ui->carta59_2->objectName().toLatin1().data(), ui->carta59_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta59_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta60_2_clicked()
{
    PtrSocketC->write(ui->carta60_2->objectName().toLatin1().data(), ui->carta60_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta60_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta61_2_clicked()
{
    PtrSocketC->write(ui->carta61_2->objectName().toLatin1().data(), ui->carta61_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta61_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta62_2_clicked()
{
    PtrSocketC->write(ui->carta62_2->objectName().toLatin1().data(), ui->carta62_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta62_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta63_2_clicked()
{
    PtrSocketC->write(ui->carta63_2->objectName().toLatin1().data(), ui->carta63_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta63_2->objectName());
    ui->Mensaje->clear();
}

void Widget::on_carta64_2_clicked()
{
    PtrSocketC->write(ui->carta64_2->objectName().toLatin1().data(), ui->carta64_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta64_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta65_2_clicked()
{
    PtrSocketC->write(ui->carta65_2->objectName().toLatin1().data(), ui->carta65_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta65_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta66_2_clicked()
{
    PtrSocketC->write(ui->carta66_2->objectName().toLatin1().data(), ui->carta66_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta66_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta67_2_clicked()
{
    PtrSocketC->write(ui->carta67_2->objectName().toLatin1().data(), ui->carta67_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta67_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta68_2_clicked()
{
    PtrSocketC->write(ui->carta68_2->objectName().toLatin1().data(), ui->carta68_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta68_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta69_2_clicked()
{
    PtrSocketC->write(ui->carta69_2->objectName().toLatin1().data(), ui->carta69_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta69_2->objectName());
    //ui->Mensaje->clear();
}

void Widget::on_carta70_2_clicked()
{
    PtrSocketC->write(ui->carta70_2->objectName().toLatin1().data(), ui->carta70_2->objectName().size());
    ui->TextEDit->appendPlainText(ui->carta70_2->objectName());
    //ui->Mensaje->clear();
}






/*#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QTextStream>
#include "mainwindow.h"
#include <QString>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(ui->enviar, SIGNAL(clicked()), this, SLOT(enviar()));
    //connect(mSocket, &QTcpSocket::readyRead, [&](){
       //QTextStream T(mSocket);
       //ui->listWidget->addItem(T.readAll());
   // });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_conectar_clicked()
{
    mSocket->connectToHost("LocalHost", 8080);
    //g = new MainWindow(this);
    //g->show();

    //this->hide();
    //g->duranteJuego=false;
    //g->CantidadParejas=35;
    //g->cronometro.setText(time.toString);
}

void Widget::enviar(){
    QString msj = "Nombre de la carta";
    QTextStream T(mSocket);
    T << msj;
    mSocket->flush();



}*/


