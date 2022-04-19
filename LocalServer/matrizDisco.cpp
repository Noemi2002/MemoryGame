#include "matrizDisco.h"
#include <tarjeta.h>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdlib>
#include <fstream>
#include <QVector>

#include "tarjeta.h"
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
        QMessageBox::critical(0, "ERROR", "No se encontró el archivo");
    }
    /*for(int t=1; t<=30; t++){
        auto iterador = NombreCartas.begin();
        QByteArray nombre = cartas[t].obtenerNombre().toUtf8();
        QByteArray imagen = cartas[t].obtenerImagen().toUtf8();
        file.write(nombre + ": " + imagen);
        file.write("\n");*/
        for(int t=1; t<=30; t++){
                QString carta = "carta"+QString::number(t);
                QByteArray imagen = TablasHash[(carta)].toUtf8();
                file.write(imagen);
                file.write("\n");

            }
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

    }
    //file.write(QByteArray("De nuevo a la prueba"));
    file.flush();
    file.close();*/



QByteArray Matriz::codificacionImagen(QString imagen){
    QByteArray b;
    QString direccionImagen = "url(://" + imagen + ")";
    b = direccionImagen.toUtf8();
    QByteArray b64 = b.toBase64();
    return b64;
    //qDebug() << b64; // "aHR0cDovL2FtaW4tYWhtYWRpLmNvbQ=="
    //qDebug() << QByteArray::fromBase64(b64); // "http://amin-ahmadi.com"
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

void Matriz::MatrizDisco(QVector<QString> &NombreImagenes, QHash<QString, QString> &TablasHash){
   /* auto iterador=NombreImagenes.begin();
    int vueltas = 0;
    for(int q=0; q<30; q++){
        while (vueltas < 15){

            ptrTarjeta = new tarjeta();
            ptrTarjeta->asignarNombre("carta" + QString::number(q));
            ptrTarjeta->asignarImagen(*iterador);
            tarjeta *ptr2Tarjeta = (tarjeta*) malloc(sizeof(tarjeta));
            *ptr2Tarjeta = *ptrTarjeta;
            cartas.append(*ptr2Tarjeta);
            //cartas[q]->asignarNombre("carta" + QString::number(q));
            //cartas[q].asignarImagen(*iterador);
            //free (ptr2Tarjeta);
            iterador++;
            vueltas++;
        }
        vueltas = 1;
        iterador = NombreImagenes.begin();

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

    return agregarImagenMatriz(respuesta);
}

QString Matriz::agregarImagenMatriz(QString nombre){
    int numero = obtenerNombreNumericoCarta(nombre);
    int fila = obtenerIndicesi(numero);
    int columna = obtenerIndicesj(numero);
    int g = 0;
    QString respuesta;
    while(g < 30){
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s == fila && h == columna){
                    respuesta = matrizMemoria[s][h] = nombre;
            }
        }
        }
        g++;
    }
    return respuesta;

}

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
            }
        }
        }
        g++;
    }
    if (respuesta == "false"){
        cambioDeImagenes(nombre, fila, columna);//paginacion("matriz.txt", nombre, numero-1);
        respuesta = paginacion("matriz.txt", nombre, numero-1);
        //respuesta = "false -> " + nuevaRespuesta;
    }

    //QByteArray ge = codificacionImagen(respuesta);
    //respuesta =  ge;
    return respuesta;
}

void Matriz::borrarTabla(QVector<QString> &NombreCartas, QHash<QString, QString> &TablasHash){
    auto iterador=NombreCartas.begin();
        for (int i=1; i<=30; i++){
            //QString file_name= QString::number(i)+".png";
            TablasHash[(*iterador)].clear();
            iterador++;
        }
}

void Matriz::cambioDeImagenes(QString imagen, int indiceActualI, int indiceActualJ){
    //paginacion("matriz.txt", nombre, numero-1);
    int g = 0;
    bool vuelta = false;
    while(g < 30){
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s != indiceActualI && h != indiceActualI && matrizMemoria[s][h] != NULL && vuelta){
                    matrizMemoria[s][h] = "false";
                    vuelta = true;
            }
        }
        }
        g++;
    }

}



void Matriz::inicio(){
    mezclarImagenes(NombreCartas);
    mezclarImagenes(NombreImagenes);
    MatrizDisco(NombreImagenes, TablasHash);
    crearMatrizMemoria(NombreCartas, TablasHash);
    EscribirMartriz("matriz.txt", TablasHash, NombreCartas);
    borrarTabla(NombreCartas, TablasHash);
}

