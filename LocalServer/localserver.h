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
    explicit LocalServer(QObject *parent = 0);
    void mezclarNombresVector();
    void repartirImagenes();
    int obtenerPuntaje();
    int devolverPageFault();
    QString obtenerCartas(int num);
    int parejasRestantes;





private slots:
    void nuevaConexion();
    void leerSocket();
    int obtenerResultado(QString uno, QString dos);
    void iniciarJuego();
    void enviar(QString mensaje, int puntos);

private:
    QTcpServer *PtrServer;
    QTcpSocket *PtrSocket;
    Matriz *Ptrmatriz;
    bool JuegoIniciado;
    QString carta1;
    QString carta2;
    int i;
    int j;
    int puntajeJugador1;

};

#endif //LOCALSERVER_H
