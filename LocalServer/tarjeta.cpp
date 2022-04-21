#include "tarjeta.h"

Tarjeta::Tarjeta(QString nombre, QString imagen)
{
    asignarNombre(nombre);
    asignarImagen(imagen);
}
void Tarjeta::asignarNombre(QString nombre){
    this->nombreCarta = nombre;
}

void Tarjeta::asignarImagen(QString imagen){
    this->imagenCarta = imagen;
    }

QString Tarjeta::obtenerNombre(){
    return this->nombreCarta;
}

QString Tarjeta::obtenerImagen(){
    return this->imagenCarta;
}
