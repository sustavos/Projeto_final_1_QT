#ifndef CADASTRADOS_H
#define CADASTRADOS_H

#include <QVector>
#include "domicilio.h"

class Cadastrados
{

private:
    QVector <Domicilio> lista;

public:
    Cadastrados();

    void inserirDomicilio(Domicilio d);

};

#endif // CADASTRADOS_H
