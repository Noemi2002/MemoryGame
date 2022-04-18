#ifndef CLIENTE_H
#define CLIENTE_H

#include <widget.h>
#include <QTcpSocket>


class Cliente
{
public:
    Cliente(Ui::Widget *ptr = 0);

private:
    Ui::Widget *ptrUtil;
    QTcpSocket *PtrSocketC;
};

#endif // CLIENTE_H
