#include "cadastrados.h"

Cadastrados::Cadastrados()
{

}

void Cadastrados::inserirDomicilio(Domicilio d){
    lista.push_back(d);
}

bool Cadastrados::VerificarExistencia(Domicilio d)
{
    if(lista.size() >= 1){
        for(int i = 0; i < lista.size(); i++){
            if((lista[i].getCep() == d.getCep()) and (lista[i].getNumero() == d.getNumero())){
                if(lista[i].getTipo() == d.getTipo()){
                    if(lista[i].getNumApt() == d.getNumApt()){
                        return 1;
                    }
                }else{
                    return 1;
                }

            }

        }
   }
   return 0;

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

int Cadastrados::getCasasCadastradas()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getTipo()== "Casa"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getAptCadastrados()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getTipo()== "Apartamento"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getComodosCadastrados()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getTipo()== "Cômodo"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getOutros()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if((lista[i].getTipo() != "Casa") and (lista[i].getTipo() != "Apartamento") and (lista[i].getTipo() != "Cômodo")){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getSemEnergia()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getEnergia() == "Não"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getSemAgua()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getAgua() == "Não"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getSemEsgoto()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getEsgoto() == "Não"){
            cont++;
        }
    }
    return cont;
}

int Cadastrados::getSemLixo()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getLixo() == "Não"){
            cont++;
        }
    }
    return cont;
}

double Cadastrados::getMaiorRenda()
{
    double cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getRenda() >= cont){
            cont = lista[i].getRenda();
        }
    }
    return cont;
}

double Cadastrados::getMenorRenda()
{
    double cont = lista[0].getRenda();

    for(int i = 1; i < lista.size(); i++){
        if(lista[i].getRenda() <= cont){
            cont = lista[i].getRenda();
        }
    }
    return cont;
}

double Cadastrados::getRendaMedia()
{
    double media;
    double cont = 0;

    for(int i = 0; i < lista.size(); i++){
            cont += lista[i].getRenda();
        }

    media = (cont)/(lista.size());

    return media;
}

int Cadastrados::getMenorPop()
{
    int cont = lista[0].getQnt_pessoas();

    for(int i = 1; i < lista.size(); i++){
        if(lista[i].getQnt_pessoas() <= cont){
            cont = lista[i].getQnt_pessoas();
        }
    }
    return cont;
}

int Cadastrados::getMaiorPop()
{
    int cont = 0;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getQnt_pessoas() >= cont){
            cont = lista[i].getQnt_pessoas();
        }
    }
    return cont;
}

int Cadastrados::getMediaPop()
{
    int media; // A média é um int pois não existe qtd. de pessoas fracionária
    int cont = 0;

    for(int i = 0; i < lista.size(); i++){
            cont += lista[i].getQnt_pessoas();
        }

    media = (cont)/(lista.size());

    return media;
}

bool Cadastrados::carregarDados(QString file)
{
    QFile arquivo(file);
    if(arquivo.isOpen())
    {
        return true;

    }else{

        arquivo.open(QIODevice::ReadOnly);

        QString linha;
        QStringList dados;

        while(!arquivo.atEnd()){
            Domicilio temp;

            linha = arquivo.readLine();
            dados = linha.split(",");

            temp.setCep(dados[0]);
            temp.setNumero(dados[1]);
            temp.setTipo(dados[2]);
            temp.setNumApt(dados[3]);
            temp.setEnergia(dados[4]);
            temp.setAgua(dados[5]);
            temp.setEsgoto(dados[6]);
            temp.setLixo(dados[7]);
            temp.setQnt_pessoas(dados[8].toInt());
            temp.setRenda(dados[9].toDouble());

            if(!VerificarExistencia(temp)){
                inserirDomicilio(temp);
            }
        }

        arquivo.close();
        return false;
    }
}

bool Cadastrados::salvarDados(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::WriteOnly);

    if(arquivo.isOpen())
    {
        for(auto a : lista){
            QString linha = a.getCep() + "," + a.getNumero() + "," + a.getTipo() + "," + a.getNumApt() + "," + a.getEnergia() + "," + a.getAgua() + "," + a.getEsgoto() + "," + a.getLixo() + "," + QString::number(a.getQnt_pessoas()) + "," + QString::number(a.getRenda());
            arquivo.write(linha.toLocal8Bit());
        }
        arquivo.close();
        return true;
    }else{
        return false;
    }

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
