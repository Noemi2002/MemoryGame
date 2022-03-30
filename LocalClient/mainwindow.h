#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

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
    void ActualizarJuego();
    void ActualizarCronometro();
    void ResultadoJuego();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
