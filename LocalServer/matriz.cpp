#include "matriz.h"
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

Matriz::Matriz(){}


/**
 * Escribe la las imágenes de las cartas en orden ascedente en el archivo txt, esto a partir de la tabla hash.
 * @brief Matriz::EscribirMartriz
 * @param filename
 * @param TablasHash
 * @param NombreCartas
 */
void Matriz::EscribirMartriz(QString filename, QHash<QString, QString> &TablasHash, QVector<QString> &NombreCartas){

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(0, "ERROR", "No se encontró el archivo");
    }
        for(int t=1; t<=30; t++){
                QString carta = "carta"+QString::number(t);
                QByteArray imagen = TablasHash[(carta)].toUtf8();
                file.write(imagen);
                file.write("\n");
            }
}


/**
 * Codifica la imagen y retorn el QByteArray de la misma.
 * @brief Matriz::codificacionImagen
 * @param imagen
 * @return
 */
QByteArray Matriz::codificacionImagen(QString imagen){
    QByteArray b;
    QString direccionImagen = "url(://" + imagen + ")";
    b = direccionImagen.toUtf8();
    QByteArray b64 = b.toBase64();
    return b64;
}


/**
 * Retorna el índice i a partir del nombre de la carta para realizar la búsqued de la imagen o agregar la imagen
 * @brief Matriz::obtenerIndicesi
 * @param valor
 * @return i
 */
int Matriz::obtenerIndicesi(int valor){

    i = (valor/10)%10;
            if(valor%10==0){
                i-=1;
            }
    return i;
}


/**
 * Retorna el índice j a partir del nombre de la carta para realizar la búsqued de la imagen o agregar la imagen
 * @brief Matriz::obtenerIndicesj
 * @param valor
 * @return
 */
int Matriz::obtenerIndicesj(int valor){

    j = valor%10 - 1;
            if (valor%10 == 0){
                j = 9;
            }
    return j;
}


/**
 * Este método se encarga de dividir el nombre de la carta y obtener solamente el número para posteriormente obtener lo índices.
 * @brief Matriz::obtenerNombreNumericoCarta
 * @param carta
 * @return s
 */
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


/**
 * Mezcla el vector con el nombre de las cartas.
 * @brief Matriz::mezclarImagenes
 * @param NombreImagenes
 */
void Matriz::mezclarImagenes(QVector<QString> &NombreImagenes){
    unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(NombreImagenes.begin(), NombreImagenes.end(), std::default_random_engine(semilla)); //default_random_engine(semilla) es el generador de los números aleatorios
}


/**
 * Guarda los datos de las cartas y sus imagenes en la tabla hash.
 * @brief Matriz::MatrizDisco
 * @param NombreCartas
 * @param TablasHash
 */
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


/**
 * Arma la matriz que va a estar en memoria.
 * @brief Matriz::crearMatrizMemoria
 * @param NombreCartas
 * @param TablaHash
 */
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


/**
 * Busca en el archivo txt cuando la imagen no está cargada en memoria.
 * @brief Matriz::paginacion
 * @param filename
 * @param carta
 * @param indice
 * @return respuesta
 */
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

    agregarImagenMatriz(carta, respuesta);
    return respuesta;
}


/**
 * Agrega la la imagen obtenida en el método de paginación en la matriz.
 * @brief Matriz::agregarImagenMatriz
 * @param nombre
 * @param imagen
 */
void Matriz::agregarImagenMatriz(QString nombre, QString imagen){
    int numero = obtenerNombreNumericoCarta(nombre);
    int fila = obtenerIndicesi(numero);
    int columna = obtenerIndicesj(numero);
    int g = 0;
    QString respuesta;
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s == fila && h == columna){
                    respuesta = matrizMemoria[s][h] = imagen;
            }
        }
    }

}


/**
 * Busca en la matriz si la imagen de la carta enviada por el cliente está en memoria, sino llama a la función de paginación y a cambioDeImagenes.
 * @brief Matriz::buscarImagenCarta
 * @param nombre
 * @return respuesta
 */
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
    }
    return respuesta;
}


/**
 * Borra la tabla hash, para que no quede en memoria.
 * @brief Matriz::borrarTabla
 * @param NombreCartas
 * @param TablasHash
 */
void Matriz::borrarTabla(QVector<QString> &NombreCartas, QHash<QString, QString> &TablasHash){
    auto iterador=NombreCartas.begin();
        for (int i=1; i<=30; i++){
            //QString file_name= QString::number(i)+".png";
            TablasHash[(*iterador)].clear();
            iterador++;
        }
}


/**
 * Este método lo que hace es quitar es quitar una carta que sea diferente a la elegida para luego agregar la que no estaba en memoria, esto
 * para que se mantengan solo 10 cartas en memoria.
 * @brief Matriz::cambioDeImagenes
 * @param imagen
 * @param indiceActualI
 * @param indiceActualJ
 */
void Matriz::cambioDeImagenes(QString imagen, int indiceActualI, int indiceActualJ){
    //paginacion("matriz.txt", nombre, numero-1);
    int g = 0;
    bool vuelta = false;
        for(int s=0; s<3; s++){
            for(int h=0; h<10; h++){
                if (s != indiceActualI && h != indiceActualJ && matrizMemoria[s][h] != "false" && !vuelta){
                    matrizMemoria[s][h] = "false";
                    vuelta = true;
            }
        }
    }

}


/**
 * Este método llama a las principales funciones de esta clae.
 * @brief Matriz::inicio
 */
void Matriz::inicio(){
    mezclarImagenes(NombreCartas);;
    MatrizDisco(NombreCartas, TablasHash);
    crearMatrizMemoria(NombreCartas, TablasHash);
    EscribirMartriz("matriz.txt", TablasHash, NombreCartas);
    borrarTabla(NombreCartas, TablasHash);
}

