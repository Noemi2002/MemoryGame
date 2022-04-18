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
    connect(PtrTiempo, SIGNAL(timeout()), this, SLOT(actualizarJuego()));

    //Funcionalidad de las cartas
    connect(ui->carta01, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta02, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta03, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta04, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta05, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta06, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta07, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta08, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta09, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta10, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta11, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta12, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta13, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta14, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta15, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta16, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta17, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta18, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta19, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta20, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta21, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta22, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta23, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta24, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta25, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta26, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta27, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta28, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta29, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));
    connect(ui->carta30, SIGNAL(clicked()), this, SLOT(cartaSeleccionada()));



    //connect(ui->carta02, SIGNAL(clicked()), this, SLOT(tarjetaDescubierta()));
    iniciarJuego();



}

void Widget::cartaSeleccionada(){
    primerCarta=qobject_cast<QPushButton*>(sender());
    //mostrarImagen();
    primerCarta->setEnabled(false);
    if (!jugadaIniciada){
        segundaCarta=primerCarta;
        jugadaIniciada=true;
    }else{
        //definirResultadoParcial();
        jugadaIniciada=false;
        }

    QString nombre = primerCarta->objectName();
    EnviarCarta(nombre);
}

void Widget::iniciarJuego(){
    jugadaIniciada=false;

    PuntajePrimerJugador = 0;
    ui->Puntaje1->setText(QString::number(PuntajePrimerJugador));

    PuntajeSegundoJugador = 0;
    ui->Puntaje2->setText(QString::number(PuntajeSegundoJugador));;

    parejasRestantes=15;

    tiempo.setHMS(0,0,0);
    ui->cronometro->setText(tiempo.toString("m:ss"));
    PtrTiempo->start(1000);
    ui->frame->setEnabled(true);

        //enable every tile and reset its image
        QList<QPushButton *> botones =  ui->frame->findChildren<QPushButton*>();
        foreach (QPushButton* b, botones) {
            b->setEnabled(true);
            b->setStyleSheet("#" + b->objectName() + "{ }");
        }
    /*tiempo.setHMS(0,0,0);
    ui->cronometro->setText(tiempo.toString("m:ss"));
    PtrTiempo->start(1000);*/

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
    mostrarImagen(QString(buffer));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mostrarImagen(QString imagen){
    primerCarta->setText(imagen);
}

void Widget::finalizarJuego(){
    if(parejasRestantes == 0){
        PtrTiempo->stop();
        QMessageBox::information(this, "Se acabó el juego", "¡Felicidades!, has ganado");
    }else{
        if (tiempo.toString()=="00:05:00" && parejasRestantes != 0){
            PtrTiempo->stop();
            QMessageBox::information(this, "Se acabó el tiempo", "¡Lo siento!, has perdido");
        }
    }
}

void Widget::actualizarJuego(){
    cronometro();
    finalizarJuego();
}

void Widget::on_Enviar_clicked(){
    PtrSocketC->write(ui->Mensaje->text().toLatin1().data(), ui->Mensaje->text().size());
    //ui->TextEDit->appendPlainText(ui->Mensaje->text());
    ui->Mensaje->clear();

    /*PtrSocketC->write(ui->Enviar->objectName().toLatin1().data(), ui->Enviar->objectName().size());
    ui->TextEDit->appendPlainText(ui->Enviar->objectName());
    ui->Mensaje->clear();*/

}

/*void Widget::avanceJuego(){

    //check if there is a match (the current tile matches the previous tile in the turn)
        if (reparto[tarjetaActual->objectName()]==reparto[tarjetaAnterior->objectName()]){
            puntaje+=15;
            ui->lblPuntaje->setText(QString::number(puntaje));
            parejasRestantes--;

            //if there is a match, find out if all tiles have been matched.
            finalizarJuego();
        }
        else{
            puntaje-=5;
            ui->lblPuntaje->setText(QString::number(puntaje));

            //disable the whole tile section so no tiles can be turned during the 1-second "memorizing period"
            ui->frame->setEnabled(false);

            //if there is no match, let user memorize tiles and after 1 second hide tiles from current turn so they can be used on another turn
            QTimer::singleShot(1000, this, SLOT(reiniciarTarjetas()));
        }
    }

}*/

void Widget::EnviarCarta(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
    ui->TextEDit->appendPlainText(nombre);
    ui->Mensaje->clear();
}
