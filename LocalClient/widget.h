#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_conectar_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
    MainWindow *g;
};
#endif // WIDGET_H
