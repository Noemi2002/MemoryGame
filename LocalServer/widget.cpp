#include "widget.h"
#include "ui_widget.h"
#include "matriz.h"
#include "localserver.h"

#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ptrLS = new LocalServer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarInterfaz()));
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
   using std::ios_base;
   using std::ifstream;
   using std::string;

   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   //
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
               >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

   stat_stream.close();

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
   vm_usage     = vsize / 1024.0;
   resident_set = rss * page_size_kb;
}

void Widget::actualizarInterfaz(){
    double vm, rss;
    process_mem_usage(vm, rss);
    ui->plainTextEdit_memoriaUso->appendPlainText("VM: " + QString::number(vm) + " - " + "RSS: " + QString::number(rss));
    //ui->plainTextEdit_memoriaUso->appendPlainText();

    int puntos = ptrLS->obtenerPuntaje();
    ui->label_Puntaje->setText(QString::number(puntos));

    int pfaults = ptrLS->devolverPageFault();
    ui->label_PF->setText(QString::number(pfaults));
}



Widget::~Widget()
{ delete ui;}





