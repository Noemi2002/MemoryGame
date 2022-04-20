#include "widget.h"
#include "ui_widget.h"
#include "matriz.h"
#include "localserver.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ptrLS = new LocalServer(this);
}

Widget::~Widget()
{ delete ui;}





