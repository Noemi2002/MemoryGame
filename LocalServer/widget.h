#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>


class LocalServer;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//class Matriz;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void actualizarInterfaz();
    void process_mem_usage(double& vm_usage, double& resident_set);
    void llamadaCartas();



private:
    Ui::Widget *ui;
    LocalServer *ptrLS;
    QTimer *timer=new QTimer();


};
#endif // WIDGET_H
