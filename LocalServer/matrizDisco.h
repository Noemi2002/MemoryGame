#ifndef MATRIZDISCO_H
#define MATRIZDISCO_H

#include<QVector>
#include <QHash>
#include<QString>
#include <random>
#include <QMatrix>
#include <QFile>
#include<string>
#include<string.h>


class Matriz
{
public:
    Matriz();
    QVector<QString> NombreCartas{"carta1","carta2","carta3","carta4","carta5","carta6","carta7",
                                   "carta8","carta9","carta10","carta11","carta12","carta13","carta14",
                                   "carta15","carta16","carta17","carta18","carta19","carta20","carta21",
                                    "carta22","carta23","carta24","carta25","carta26","carta27","carta28",
                                    "carta29","carta30"};


    QVector<QString> NombreImagenes{"1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png" ,"10.png",
                                    "11.png" ,"12.png" ,"13.png", "14.png", "15.png"};



    QHash<QString, QString> MatrizActual;
    QHash<QString, QString> TablasHash;


private:
    int i;
    int j;

    QString matrizMemoria[3][10];



public slots:
    void mezclarImagenes(QVector<QString> &NombreImagenes);
    void MatrizDisco(QVector<QString> &NombreCartas, QHash<QString, QString> &reparto);
    void crearMatrizMemoria(QVector<QString> &NombreCartas, QHash<QString, QString> &TablaHash);
    int obtenerIndicesi(int valor);
    int obtenerIndicesj(int valor);
    int obtenerNombreNumericoCarta(QString carta);
    void EscribirMartriz(QString filename, QHash<QString, QString> &reparto, QVector<QString> &NombreImagenes);
    QString buscarImagenCarta(QString nombre);
    QString paginacion(QString file, QString carta, int indice);
    void inicio();


private slots:

};

#endif // MATRIZDISCO_H
