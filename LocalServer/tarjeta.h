#ifndef TARJETA_H
#define TARJETA_H
#include <QString>


class Tarjeta
{
public:
    Tarjeta(QString nombre, QString imagen);

private:
    QString nombreCarta;
    QString imagenCarta;


public:
    QString obtenerNombre();
    QString obtenerImagen();
    void asignarNombre(QString nombre);
    void asignarImagen(QString imagen);
};


#endif // TARJETA_H
