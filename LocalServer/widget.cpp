#include "widget.h"
#include "ui_widget.h"
#include "matriz.h"
#include "localserver.h"

#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>

using std::ios_base;
using std::ifstream;
using std::string;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ptrLS = new LocalServer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarInterfaz()));
    timer->start(1000);
    llamadaCartas();
}

void Widget::llamadaCartas(){
    for(int i=0; i<10; i++){
        QString cartaActual = ptrLS->obtenerCartas(i);
        ui->plainTextEdit_memoria->appendPlainText(cartaActual);
    }

    for(int a=11; a<=30; a++){
        QString cartaFuera = ptrLS->obtenerCartas(a-1);
        ui->plainTextEdit_disco->appendPlainText(cartaFuera);
    }
}

void Widget::process_mem_usage(double& vm_usage, double& resident_set)
{

   //ui->plainTextEdit_memoriaUso->clear();

    vm_usage     = 0.0;
   resident_set = 0.0;

   ifstream stat_stream("/proc/self/stat",ios_base::in); //obtiene la información del directorio proc

   // variables para obtener la información
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;

   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss;

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}

void Widget::actualizarInterfaz(){

    double vm, rss;
    process_mem_usage(vm, rss);
    ui->plainTextEdit_memoriaUso->appendPlainText("Virtual Memory: " + QString::number(vm));
    ui->plainTextEdit_memoriaUso->appendPlainText("\nResident set size: " + QString::number(rss));

    int puntos = ptrLS->obtenerPuntaje();
    ui->label_Puntaje->setText(QString::number(puntos));

    int pfaults = ptrLS->devolverPageFault();
    ui->label_PF->setText(QString::number(pfaults));
}



Widget::~Widget()
{ delete ui;}





