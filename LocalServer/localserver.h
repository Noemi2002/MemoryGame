#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QTcpServer>
#include<random>
#include<QHash>
#include <widget.h>

class QTcpSocket;
class Matriz;
class QWidget;

class LocalServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit LocalServer(QObject *parent = 0, Ui::Widget *ptr = 0);
    bool JuegoIniciado;
    int i;
    int j;




    int puntajeJugador1;
    int puntajeJugador2;
    void mezclarNombresVector();
    void repartirImagenes();
    void enviar(QString mensaje);

private slots:
    void nuevaConexion();
    void leerSocket();
    //void pedirImagen(QString carta);
    void iniciarJuego();

private:

    QTcpServer *PtrServer;
    QTcpSocket *PtrSocket;
    Matriz *Ptrmatriz;
    Ui::Widget *ptrUso;

};

#endif //LOCALSERVER_H
