#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(PtrTiempo, SIGNAL(timeout()), this, SLOT(ActualizarJuego()));
    time.setHMS(0,0,0);
    ui->cronometro->setText(time.toString("m:ss"));
    PtrTiempo->start(1000);
}

void MainWindow::ResultadoJuego(){
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


MainWindow::~MainWindow()
{
    delete ui;
}
