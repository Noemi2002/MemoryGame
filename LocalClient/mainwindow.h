/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
//#include "widget.h"

namespace Ui {
class MainWindow;
}

class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *PtrTiempo = new QTimer();
    QTime time;
    int CantidadParejas;
    QMessageBox ganador;
    bool duranteJuego;

private slots:
    //void ActualizarJuego();
    //void ActualizarCronometro();
    //void ResultadoJuego();
    void enviarNombreCarta();
    void enviarDatos(const QString msj);

    void on_carta1_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *PtrJuego;
};

#endif // MAINWINDOW_H*/

