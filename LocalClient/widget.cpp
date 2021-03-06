#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


/**
 * Conexión del cliente al servidor mediante TCPSockets
 * @brief Widget::Widget
 * @param parent
 */
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


/**
 * Este método recibe la carta seleccionada y la guarda en un puntero
 * Hace la llamada a al método que envia la carta la servidor
 * @brief Widget::cartaSeleccionada
 */
void Widget::cartaSeleccionada(){

    primerCarta=qobject_cast<QPushButton*>(sender());
    primerCarta->setEnabled(false);
    if (!jugadaIniciada){ //Entra aquí si es la primer carta que se escoge (de cada turno).
        segundaCarta=primerCarta;
        jugadaIniciada=true;
        turnos += 1;
    }else{ //Entra aquí si es la segunda carta la que se escoge.
        turnos += 2;
        jugadaIniciada=false;
        }

    QString nombre = primerCarta->objectName();
    EnviarCarta(nombre);
}


/**
 * Este método actualiza el cronometro casa segundo.
 * @brief Widget::cronometro
 */
void Widget::cronometro(){
        tiempo=tiempo.addSecs(1);
        ui->cronometro->setText(tiempo.toString("m:ss"));
}


/*
 *
 */
/**
 * Recibe y lee la dirección de la imagen que manda el servidor.
 * Manda a llamar a la función que va a mostrar la imagen con la dirección recibida.
 * @brief Widget::leer
 */
void Widget::leer(){
    QByteArray buffer;
    buffer.resize(PtrSocketC->bytesAvailable());
    PtrSocketC->read(buffer.data(), buffer.size());
    mostrarImagen(obtenerImagen(QString(buffer)));
}


Widget::~Widget()
{
    delete ui;
}


/**
 * Busca la imagen, según la dirección que recibió y le cambia el estilo al botón para mostrarla.
 * @brief Widget::mostrarImagen
 * @param imagen
 */
void Widget::mostrarImagen(QString imagen){
    primerCarta->setStyleSheet("#" + primerCarta->objectName() + "{ background-image:" + imagen + "}");
}


/**
 * Hace la comprobación de tiempo o de la cantida de parejas restantes para dar por acabado el juego
 * @brief Widget::finalizarJuego
 */
void Widget::finalizarJuego(){
    if(parejasRestantes == 0){
        PtrTiempo->stop();
        QMessageBox::information(this, "Se acabó el juego", "¡Felicidades!, has ganado");
    }else{
        if (tiempo.toString()=="00:02:00" && parejasRestantes != 0){
            PtrTiempo->stop();
            QMessageBox::information(this, "Se acabó el tiempo", "¡Lo siento!, has perdido");
        }
    }
}


/**
 * Este método se está llamando constantemente para que el crónometro se muestre en pantalla en tiempo real
 * y llama al método de actualizarJuego para que se acabe el juego en el tiempo correcto.
 * @brief Widget::actualizarJuego
 */
void Widget::actualizarJuego(){
    cronometro();
    finalizarJuego();
}


/**
 * En caso de que las catas no tengan la misma imagen, se cambia el estilo del botón-carta al que tenía al principio y se vuelven a habilitar
 * para que sea nuevamente escogidos.
 * @brief Widget::reiniciarEstadoTarjetas
 */
void Widget::reiniciarEstadoTarjetas(){ //reiniciar tarjetas
    primerCarta->setStyleSheet("#" + primerCarta->objectName() + "{ }");
    segundaCarta->setStyleSheet("#" + primerCarta->objectName() + "{ }");

    primerCarta->setEnabled(true);
    segundaCarta->setEnabled(true);

    ui->frame->setEnabled(true);
}


/**
 * Este método identifica si hubo cambio de puntaje: si hubo deja las cartas con la imagen, resta a las perejas que quedan y llama a finalizarJuego
 * en caso de que no hubieran deja las imagenes por un rato pequeño para que el jugador las vea y luego manda a que sean volteadas.
 * @brief Widget::avanceJuego
 */
void Widget::avanceJuego(){
    if (!aumentoPuntaje){
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000, this, SLOT(reiniciarEstadoTarjetas()));
    }else{
        parejasRestantes-=1;
        ui->Puntaje1->setText(QString::number(PuntajePrimerJugador));
        finalizarJuego();
        aumentoPuntaje = false;
        }
}


/**
 *  * Este método recibe el dato enviado por el servidor con la dirección de la imagen y los puntos obtenidos, los separa
 * en caso de que hubiera aumento de puntos lo muestra en la interfaz del juego, también verifica si hay dos cartas volteadas para que se llame al método
 * avanceJuego para voltear las cartas si es necesario.
 * @brief Widget::obtenerImagen
 * @param mensaje
 * @return imagen
 */
QString Widget::obtenerImagen(QString mensaje){
    std::string datoOriginal = mensaje.toStdString();
    std::string delimiter = ":";
    std::string imagen;
    std::string puntos;

    size_t pos = 0;
    while ((pos = datoOriginal.find(delimiter)) != std::string::npos) {
        imagen = datoOriginal.substr(0, pos); //Guarda la primer parte del string recibido
        puntos = datoOriginal.erase(0, pos + delimiter.length()); //Almacena la segunda parte del string recibido
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


/**
 * Este método envía el nombre de la carta la servidor a través del socket.
 * @brief Widget::EnviarCarta
 * @param nombre
 */
void Widget::EnviarCarta(QString nombre){
    PtrSocketC->write(nombre.toLatin1().data(), nombre.size());
}


/**
 * Este es el método principal del cliente, donde se inicializan todas las variables importantes del juego
 * @brief Widget::iniciarJuego
 */
void Widget::iniciarJuego(){
    jugadaIniciada=false;
    aumentoPuntaje = false;

    PuntajePrimerJugador = 0;
    ui->Puntaje1->setText(QString::number(PuntajePrimerJugador));

    PuntajeSegundoJugador = 0;

    parejasRestantes=15;

    tiempo.setHMS(0,0,0);
    ui->cronometro->setText(tiempo.toString("m:ss"));
    PtrTiempo->start(1000);
    ui->frame->setEnabled(true);

}
