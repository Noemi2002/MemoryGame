#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    QTime tiempo;
    int parejasRestantes;
    int PuntajePrimerJugador;
    int PuntajeSegundoJugador;
    QPushButton* primerCarta;
    QPushButton* segundaCarta;
    bool jugadaIniciada;


private slots:
    void leer();

    void on_Enviar_clicked();
    void iniciarJuego();
    void cronometro();
    void cartaSeleccionada();
    void finalizarJuego();
    void EnviarCarta(QString nombre);
    void actualizarJuego();
    void mostrarImagen(QString imagen);
    void avanceJuego();




private:
    Ui::Widget *ui;
    QTcpSocket *PtrSocketC;
    QTimer *PtrTiempo=new QTimer();
};
#endif // WIDGET_H

