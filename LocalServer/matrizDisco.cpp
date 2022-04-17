#include "matrizDisco.h"
#include <tarjeta.h>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdlib>
#include <fstream>

#include "widget.h"
#include "ui_widget.h"

using namespace std;

Matriz::Matriz(Ui::Widget *ptr)
{
    ptrUso = ptr;

}
void Matriz::EscribirMartriz(QString filename, QHash<QString, QString> &TablasHash, QVector<QString> &NombreCartas){

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){
        //QMessageBox::critical(this, "ERROR", "No se encontró el archivo");
    }
    //auto iterador = NombreCartas.begin();
      //  QByteArray nombre = cartas[t].obtenerNombre().toUtf8();
        //QByteArray imagen = cartas[t].obtenerImagen().toUtf8();
        //file.write(nombre + ": " + imagen);
        for(int t=1; t<=30; t++){
                QString carta = "carta"+QString::number(t);
                QByteArray imagen = TablasHash[(carta)].toUtf8();
                file.write(carta.toUtf8() + ":" + imagen);
                file.write("\n");

            }
    //QFile file(filename);
    //if(!file.open(QIODevice::WriteOnly)){
        //QMessageBox::critical(this, "ERROR", "No se encontró el archivo");
   // }
    /*auto iterador=NombreCartas.begin();
        for (int s=0; s <3; s++){ //filas
            for(int j=0; j<10; j++){ //columnas

        QByteArray carta = iterador->toUtf8();
        QByteArray imagen = TablasHash[(*iterador)].toUtf8();
        file.write(carta + ":" + imagen + "-");
        iterador++;
        }
       file.write("\n");

    }*/
    //file.write(QByteArray("De nuevo a la prueba"));
    file.flush();
    file.close();

}

int Matriz::obtenerIndicesi(int valor){

    i = (valor/10)%10;
            if(valor%10==0){
                i-=1;
            }
    return i;
}

int Matriz::obtenerIndicesj(int valor){

    j = valor%10 - 1;
            if (valor%10 == 0){
                j = 9;
            }
    return j;

}

int Matriz::obtenerNombreNumericoCarta(QString carta){
    std::string s = carta.toStdString();
    std::string delimiter = "carta";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
    }
    return stoi(s);


}

void Matriz::mezclarImagenes(QVector<QString> &NombreImagenes){
    unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(NombreImagenes.begin(), NombreImagenes.end(), std::default_random_engine(semilla)); //default_random_engine(semilla) es el generador de los números aleatorios
}

void Matriz::MatrizDisco(QVector<QString> &NombreCartas, QHash<QString, QString> &TablasHash){
    /*auto iterador=NombreImagenes.begin();
    auto interadorCartas = cartas.begin();
    int vueltas = 1;
    for(int q=0; q<30; q++){
        while (vueltas <= 15){

            //ptrTarjeta = ;
            interadorCartas = new tarjeta("carta"+QString::number(q), *iterador);
            interadorCartas++;
            iterador++;
            vueltas++;
        }
        vueltas = 1;
        iterador = NombreCartas.begin();

    }*/


    auto iterador=NombreCartas.begin();
    for (int i=1; i<=15; i++){
        QString file_name= QString::number(i)+".png";
        TablasHash[(*iterador)]=file_name;
        iterador++;
        TablasHash[(*iterador)]=file_name;
        iterador++;
    }
}

void Matriz::crearMatrizMemoria(QVector<QString> &NombreCartas, QHash<QString, QString> &TablaHash){
    auto iterador2 =NombreCartas.begin();
    int g = 0;

    while(g < 10){
        int idCarta = obtenerNombreNumericoCarta(*iterador2);
        int fila = obtenerIndicesi(idCarta);
        int columna = obtenerIndicesj(idCarta);
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s == fila && h == columna){
                    matrizMemoria[s][h] = TablaHash[(*iterador2)];
                }else{
                    if (matrizMemoria[s][h] == NULL){
                    matrizMemoria[s][h] = "false";}
                }
            }
        }
        iterador2++;
        g++;

    }

}

QString Matriz::paginacion(QString filename, QString carta, int indice){

    QString respuesta;
    QFile file(filename);
    if(!file.exists()){
        QMessageBox::critical(0, "ERROR", "No se encontró el archivo");
    }

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(0, "ERROR", "No se pudo abrir el archivo");
    }

    int cont = 0;
    QTextStream stream(&file);
    while (!stream.atEnd()){
        QString line = stream.readLine();
        if (cont == indice){
            respuesta = line;
        }
        cont++;
    }

    file.close();
    return respuesta;
    /* QTextStream stream(&filename);
    ifstream archivo("matriz.txt");
    string carta12 = carta.toStdString();

    int cont = 0;
    while (getline(archivo, carta12)){
        QString line = stream.readLine();

        if (indice == cont){
            ptrUso->texto->appendPlainText(line);
        }
        cont++;
    }*/

}



    /*QString line;
    QFile file(filename);
    if (file.exists()){
        QTextStream stream(&file);
        line = stream.readLine();

        //ptrUso->texto->appendPlainText(stream.readAll());
        // ptrUso->texto->appendPlainText("Documento no encontrado");
    }

    if(!file.open(QIODevice::ReadOnly)){
        ptrUso->texto->appendPlainText("Error");
    }


   // while(!stream.atEnd()){
     //   QString line = stream.readLine();
       // ptrUso->texto->appendPlainText();

   // }

    file.close();
    return line;

    /*QTextStream stream(&filename);
    ifstream archivo("matriz.txt");
    QString devuelta;
    std::string elegida;

    if (filename.isEmpty())     // Confirmar si no se selecciona ningún archivo, devolver
            return;
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while (!file.atEnd())
            {
                QByteArray line = file.readLine();
                QString str(line);
                ptrUso->texto->setPlainText(str);
                devuelta = str;
            }*/



        //return devuelta;

QString Matriz::buscarImagenCarta(QString nombre){
    int numero = obtenerNombreNumericoCarta(nombre);
    int fila = obtenerIndicesi(numero);
    int columna = obtenerIndicesj(numero);
    int g = 0;
    QString respuesta;
    while(g < 30){
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s == fila && h == columna){
                    respuesta = matrizMemoria[s][h];
                    //break;
            }
        }
        }
        g++;
    }
    if (respuesta == "false"){
        //respuesta = "Buscando imagen...";
        QString nuevaRespuesta = paginacion("matriz.txt", nombre, numero);
        //paginacion("matriz.txt", nombre, numero);
        respuesta = "false->" + nuevaRespuesta;
    }
    return respuesta;
}

void Matriz::inicio(){
    mezclarImagenes(NombreCartas);
    MatrizDisco(NombreCartas, TablasHash);
    crearMatrizMemoria(NombreCartas, TablasHash);
    EscribirMartriz("matriz.txt", TablasHash, NombreCartas);
    //buscarImagenCarta("carta1");
    //paginacion("matriz.txt", "carta12", 11);


}

