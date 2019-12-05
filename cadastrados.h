#ifndef CADASTRADOS_H
#define CADASTRADOS_H

#include <QVector>
#include <algorithm>
#include <QObject>
#include <QFile>
#include <QFileDialog>
#include "domicilio.h"

class Cadastrados
{

private:
    QVector <Domicilio> lista;

public:
    Cadastrados();
    void inserirDomicilio(Domicilio d);
    bool VerificarExistencia(Domicilio d);

    void ordenarCEP();
    void ordernarNum();
    void ordernarRenda();

    int getCasasCadastradas();
    int getAptCadastrados();
    int getComodosCadastrados();
    int getOutros();

    int getSemEnergia();
    int getSemAgua();
    int getSemEsgoto();
    int getSemLixo();

    double getMaiorRenda();
    double getMenorRenda();
    double getRendaMedia();

    int getMenorPop();
    int getMaiorPop();
    int getMediaPop();

    bool carregarDados(QString file);
    bool salvarDados(QString file);

    void limparVec();
    int size();
    Domicilio operator[](int indice);
};

bool compararCEP(Domicilio d1, Domicilio d2);
bool compararNum(Domicilio d1, Domicilio d2);
bool compararRenda(Domicilio d1, Domicilio d2);

#endif // CADASTRADOS_H
