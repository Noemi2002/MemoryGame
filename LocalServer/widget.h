#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include<QVector>
#include <QHash>
#include<QString>
#include <random>
#include <QMatrix>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Matriz;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();



    QHash<QString, QString> reparto;
    //QHash<QString, QString> MatrizActual;
    int puntajeJugador;
    int i;
    int j;




private slots:
    void nuevaConexion();
    void leerSocket();
    //void pedirImagen(QString carta);
    void iniciarJuego();
    void on_Enviar_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *PtrServer;
    QTcpSocket *PtrSocket;
    Matriz *Ptrmatriz;
};
#endif // WIDGET_H







