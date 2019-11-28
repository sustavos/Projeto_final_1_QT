#ifndef DOMICILIO_H
#define DOMICILIO_H

#include <QString>

class Domicilio{

private:
    QString cep;
    QString numero;

    QString tipo;
    QString energia;
    QString agua;
    QString esgoto;
    QString lixo;

    int qnt_pessoas;
    double renda;

public:
    Domicilio();
    Domicilio(QString c, QString n, QString t, QString e, QString a, QString es, QString l, int p, double r);

    QString getCep() const;
    void setCep(const QString &value);
    QString getNumero() const;
    void setNumero(const QString &value);
    QString getTipo() const;
    void setTipo(const QString &value);

    QString getEnergia() const;
    void setEnergia(const QString &value);
    QString getAgua() const;
    void setAgua(const QString &value);
    QString getEsgoto() const;
    void setEsgoto(const QString &value);
    QString getLixo() const;
    void setLixo(const QString &value);

    int getQnt_pessoas() const;
    void setQnt_pessoas(int value);
    double getRenda() const;
    void setRenda(double value);

    QString definirDensidade();
    QString definirGrupoSocial();

};

#endif // DOMICILIO_H
