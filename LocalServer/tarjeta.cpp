#include "tarjeta.h"
#include <QString>

tarjeta::tarjeta(QString nombre, QString imagen)
{
    nombreCarta = nombre;
    imagenCarta = imagen;
}

QString tarjeta::obtenerNombre(){
    return nombreCarta;
}

QString tarjeta::obtenerImagen(){
    return imagenCarta;
}

