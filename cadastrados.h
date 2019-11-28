#ifndef CADASTRADOS_H
#define CADASTRADOS_H

#include <QVector>
#include <algorithm>
#include <QObject>
#include "domicilio.h"

class Cadastrados
{

private:
    QVector <Domicilio> lista;

public:
    Cadastrados();
    void inserirDomicilio(Domicilio d);

    void ordenarCEP();
    void ordernarNum();
    void ordernarRenda();

    int size();
    Domicilio operator[](int indice);
};

bool compararCEP(Domicilio d1, Domicilio d2);
bool compararNum(Domicilio d1, Domicilio d2);
bool compararRenda(Domicilio d1, Domicilio d2);

#endif // CADASTRADOS_H
