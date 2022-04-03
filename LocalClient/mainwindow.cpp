/*#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "widget.h"
#include <QTcpSocket>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PtrJuego = new QTcpSocket(this);
    //conectar a servidor en esta linea.
    PtrJuego->connectToHost("LocalHost", 8080);

    //connect(PtrTiempo, SIGNAL(timeout()), this, SLOT(ActualizarJuego()));
    //connect(ui->carta1, SIGNAL(clicked()), this, SLOT(enviarNombreCarta()));

    /*time.setHMS(0,0,0);
    ui->cronometro->setText(time.toString("m:ss"));
    PtrTiempo->start(1000);
}

void MainWindow::enviarNombreCarta(){
        enviarDatos("Nombre de la carta");

}

void MainWindow::enviarDatos(const QString msj){
        QTextStream T(PtrJuego);
        T << msj;
        PtrJuego->flush();
}

/*void MainWindow::ResultadoJuego(){
    ganador.setWindowTitle("¡Se acabó el juego!");
    ganador.setIcon(QMessageBox::Information);
    ganador.button(QMessageBox::Yes);
    if (CantidadParejas == 0 && (ui->Puntaje1->text().toInt() < ui->Puntaje2->text().toInt())){
        PtrTiempo->stop();
        ganador.setText("El jugador 1 ha ganado");
        QCoreApplication::quit();

    }else{
        PtrTiempo->stop();
        ganador.setText("El jugador 2 ha ganado");
        QCoreApplication::quit();

    }

}

void MainWindow::ActualizarCronometro(){
    time = time.addSecs(1);
    ui->cronometro->setText(time.toString("m:ss"));
}

void MainWindow::ActualizarJuego(){
    ActualizarCronometro();
    ResultadoJuego();

}

void MainWindow::enviarNombreCarta(){
    QTextStream T(PtrJuego);
    T << "Nombre de carta";
    PtrJuego->flush();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_carta1_clicked()
{
    if(PtrJuego){
        enviarDatos("Nombre de la carta");
    }
}*/
