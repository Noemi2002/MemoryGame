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

    iniciarJuego();



}

void Widget::cartaSeleccionada(){ //Tarjeta descubierta

    primerCarta=qobject_cast<QPushButton*>(sender());
    primerCarta->setEnabled(false);
    if (!jugadaIniciada){
        segundaCarta=primerCarta;
        jugadaIniciada=true;
        turnos += 1;
    }else{
        turnos += 2;
        //ui->TextEDit->appendPlainText(QString(aumentoPuntaje));
        /*if (turnos%2 == 0){
            avanceJuego();}*/
        jugadaIniciada=false;
        }

    QString nombre = primerCarta->objectName();
    EnviarCarta(nombre);
}

void Widget::iniciarJuego(){
    jugadaIniciada=false;
    aumentoPuntaje = false;

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
        /*QList<QPushButton *> botones =  ui->frame->findChildren<QPushButton*>();
        foreach (QPushButton* b, botones) {
            b->setEnabled(true);
            b->setStyleSheet("#" + b->objectName() + "{ }");*/

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
    mostrarImagen(obtenerImagen(QString(buffer)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mostrarImagen(QString imagen){
    primerCarta->setText(imagen);
}

void Widget::finalizarJuego(){ //Resultado final
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

void Widget::reiniciarEstadoTarjetas(){ //reiniciar tarjetas
    primerCarta->setText("");
    segundaCarta->setText("");

    primerCarta->setEnabled(true);
    segundaCarta->setEnabled(true);

    ui->frame->setEnabled(true);
}

void Widget::on_Enviar_clicked(){
    PtrSocketC->write(ui->Mensaje->text().toLatin1().data(), ui->Mensaje->text().size());
    //ui->TextEDit->appendPlainText(ui->Mensaje->text());
    ui->Mensaje->clear();

    /*PtrSocketC->write(ui->Enviar->objectName().toLatin1().data(), ui->Enviar->objectName().size());
    ui->TextEDit->appendPlainText(ui->Enviar->objectName());
    ui->Mensaje->clear();*/

}

void Widget::avanceJuego(){ //resultado parcial
    if (!aumentoPuntaje){
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000, this, SLOT(reiniciarEstadoTarjetas()));
    }else{
        ui->Puntaje1->setText(QString::number(PuntajePrimerJugador));
        finalizarJuego();
        aumentoPuntaje = false;
        }
}

QString Widget::obtenerImagen(QString mensaje){
    std::string datoOriginal = mensaje.toStdString();
    std::string delimiter = ":";
    std::string imagen;
    std::string puntos;

    size_t pos = 0;
    while ((pos = datoOriginal.find(delimiter)) != std::string::npos) {
        imagen = datoOriginal.substr(0, pos);
        puntos = datoOriginal.erase(0, pos + delimiter.length());
    }
    if (stoi(puntos) != 0 && stoi(puntos)%5 == 0){
        aumentoPuntaje = true;
        PuntajePrimerJugador += stoi(puntos);
        ui->Puntaje1->setText(QString::number(PuntajePrimerJugador));
    }
    if (turnos%3 == 0 && turnos != 0){
        avanceJuego();}
    return QString::fromStdString(imagen);

}

void Widget::EnviarCarta(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
    ui->TextEDit->appendPlainText(nombre);
    ui->Mensaje->clear();
}
