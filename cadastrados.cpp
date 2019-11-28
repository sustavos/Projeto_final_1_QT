#include "cadastrados.h"

Cadastrados::Cadastrados()
{

}

void Cadastrados::inserirDomicilio(Domicilio d){
    lista.push_back(d);
}

int Cadastrados::size()
{
    return lista.size();
}

Domicilio Cadastrados::operator[](int indice)
{
    return lista[indice];
}

void Cadastrados::ordenarCEP()
{
    std::sort(lista.begin(),lista.end(), compararCEP);
}

void Cadastrados::ordernarNum()
{
    std::sort(lista.begin(), lista.end(), compararNum);
}

void Cadastrados::ordernarRenda()
{
    std::sort(lista.begin(), lista.end(), compararRenda);
}

bool compararCEP(Domicilio d1, Domicilio d2)
{
    return d1.getCep() < d2.getCep();
}

bool compararNum(Domicilio d1, Domicilio d2)
{
    return d1.getNumero().toDouble() < d2.getNumero().toDouble();
}

bool compararRenda(Domicilio d1, Domicilio d2)
{
    return d1.getRenda() < d2.getRenda();
}
