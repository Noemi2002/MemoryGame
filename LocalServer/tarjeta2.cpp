#include "tarjeta.h"
#include <QString>

tarjeta::tarjeta(Qstring nombre, QString imagen){

    asignarNombre(nombre);
    asignarImagen(imagen);
}
void tarjeta::asignarNombre(QString nombre){
    this->nombreCarta = nombre;
}

void tarjeta::asignarImagen(QString imagen){
    this->imagenCarta = imagen;
    }

QString tarjeta::obtenerNombre(){
    return this->nombreCarta;
}

QString tarjeta::obtenerImagen(){
    return this->imagenCarta;
}

