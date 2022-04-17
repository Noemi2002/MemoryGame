#ifndef TARJETA_H
#define TARJETA_H

#include <QString>


class tarjeta
{
public:
    tarjeta(QString nombre, QString imagen);

private:
    QString nombreCarta;
    QString imagenCarta;


public:
    QString obtenerNombre();
    QString obtenerImagen();
};

#endif // TARJETA_H
