#include "domicilio.h"

QString Domicilio::getCep() const
{
    return cep;
}

void Domicilio::setCep(const QString &value)
{
    cep = value;
}

QString Domicilio::getNumero() const
{
    return numero;
}

void Domicilio::setNumero(const QString &value)
{
    numero = value;
}

QString Domicilio::getTipo() const
{
    return tipo;
}

QString Domicilio::getNumApt() const
{
    return numApt;
}

void Domicilio::setNumApt(const QString &value)
{
    numApt = value;
}

void Domicilio::setTipo(const QString &value)
{
    tipo = value;
}

QString Domicilio::getEnergia() const
{
    return energia;
}

void Domicilio::setEnergia(const QString &value)
{
    energia = value;
}

QString Domicilio::getAgua() const
{
    return agua;
}

void Domicilio::setAgua(const QString &value)
{
    agua = value;
}

QString Domicilio::getEsgoto() const
{
    return esgoto;
}

void Domicilio::setEsgoto(const QString &value)
{
    esgoto = value;
}

QString Domicilio::getLixo() const
{
    return lixo;
}

void Domicilio::setLixo(const QString &value)
{
    lixo = value;
}

int Domicilio::getQnt_pessoas() const
{
    return qnt_pessoas;
}

void Domicilio::setQnt_pessoas(int value)
{
    if(value >= 1){
        qnt_pessoas = value;
    }else{
        qnt_pessoas = 1; // Impede de adicionar famílias com 0 pessoas
    }

    densidade = definirDensidade();

}

double Domicilio::getRenda() const
{
    return renda;
}

void Domicilio::setRenda(double value)
{
    renda = value;
    gpSocial = definirGrupoSocial();
}

QString Domicilio::definirDensidade()
{
    if(qnt_pessoas<=3){
        return "Baixo";
    }else{
        if(qnt_pessoas<=5){
            return "Médio";
        }else{
            return "Alto";
        }
    }
}

QString Domicilio::definirGrupoSocial()
{
    float renda_capita = (float)renda/qnt_pessoas;

    if(renda_capita <= 172){
        return "Extremamente pobre";
    }else{
        if(renda_capita <= 300){
            return "Pobre";
        }else{
            if(renda_capita <= 500){
                return "Vulnerável";
            }else{
               return "Fora de risco";
            }
        }
    }
}

Domicilio::Domicilio(QString c, QString n, QString t, QString nt, QString e, QString a, QString es, QString l, int p, double r)
{
    setCep(c);
    setNumero(n);
    setTipo(t);
    setNumApt(nt);
    setEnergia(e);
    setAgua(a);
    setEsgoto(es);
    setLixo(l);
    setQnt_pessoas(p);
    setRenda(r);
}

QString Domicilio::getGpSocial() const
{
    return gpSocial;
}

QString Domicilio::getDensidade() const
{
    return densidade;
}

Domicilio::Domicilio()
{

}
