#include "widget.h"
#include "ui_widget.h"
#include "matrizDisco.h"
#include "localserver.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Ui::Widget* servidor = this->ui;
    ptrLS = new LocalServer(this, servidor);
}

Widget::~Widget()
{ delete ui;}

void Widget::on_Enviar_clicked()
{
    ptrLS->enviar(ui->mensaje->text(), 0);
    ui->texto->appendPlainText(ui->mensaje->text());
    ui->mensaje->clear();
}

void Widget::anadirText(QString texto){
    ui->texto->setReadOnly(true);
    ui->texto->appendPlainText(texto);

}




