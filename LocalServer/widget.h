#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void nuevaConexion();
    void leerSocket();

    void on_Enviar_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *PtrServer;
    QTcpSocket *PtrSocket;
};
#endif // WIDGET_H







/*#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class LocalServer;
class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_clicked();

    //void on_enviar_clicked();

    //void on_quitar_clicked();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
    QTcpSocket *PtrComunicacion;

};
#endif // WIDGET_H*/

