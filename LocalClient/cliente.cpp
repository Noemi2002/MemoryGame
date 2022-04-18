#include "cliente.h"
#include "widget.h"
#include "ui_widget.h"

#include <QTcpSocket>

Cliente::Cliente(Ui::Widget *ptr)
{

    ptrUtil = ptr;
    PtrSocketC = new QTcpSocket();
    PtrSocketC->connectToHost("localhost", 8080);

    if(PtrSocketC->waitForConnected(3000)){
        QMessageBox::information(0, "Excelente", "Se conectó al servidor correctamente");

    }else{
        QMessageBox::critical(0, "ERROR", "No se pudo conectar al servidor");

    }
    //connect
    //connect(PtrSocketC, SIGNAL(readyRead()), this, SLOT(leer()));
    //connect(PtrTiempo, SIGNAL(timeout()), this, SLOT(actualizarJuego()));

}
