#include "matrizDisco.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <cstdlib>
#include <fstream>

Matriz::Matriz()
{


}
void Matriz::EscribirMartriz(QString filename, QHash<QString, QString> &TablasHash, QVector<QString> &NombreCartas){

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){
        //QMessageBox::critical(this, "ERROR", "No se encontró el archivo");
    }
    auto iterador=NombreCartas.begin();
        for (int s=0; s <6; s++){ //filas
            for(int j=0; j<5; j++){ //columnas

        QByteArray carta = iterador->toUtf8();
        QByteArray imagen = TablasHash[(*iterador)].toUtf8();
        file.write(carta + ":" + imagen + "-");
        iterador++;
        }
       file.write("\n");

    }
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

    while(g < 30){
        int idCarta = obtenerNombreNumericoCarta(*iterador2);
        int fila = obtenerIndicesi(idCarta);
        int columna = obtenerIndicesj(idCarta);
        for(int s=0; s<6; s++){
            for(int h=0; h<5; h++){
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


QString Matriz::buscarImagenCarta(QString nombre){
    int numero = obtenerNombreNumericoCarta(nombre);
    int fila = obtenerIndicesi(numero);
    int columna = obtenerIndicesj(numero);
    int g = 0;
    QString respuesta;
    while(g < 30){
        for(int s=0; s<6; s++){
            for(int h=0; h<5; h++){
                if (s == fila && h == columna){
                    respuesta = matrizMemoria[s][h];
                    //break;
            }
        }
        }
        g++;
    }
    //if (respuesta == "false"){
      //  QString nuevaRespuesta = paginacion(nombre);
        //respuesta = nuevaRespuesta;
    //}
    return respuesta;
}

void Matriz::inicio(){
    mezclarImagenes(NombreCartas);
    MatrizDisco(NombreCartas, TablasHash);
    crearMatrizMemoria(NombreCartas, TablasHash);
    EscribirMartriz("matriz.txt", TablasHash, NombreCartas);
    buscarImagenCarta("carta1");

}

