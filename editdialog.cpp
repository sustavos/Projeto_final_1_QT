#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);

    apagar = false;
    novo = false;

}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::addObjeto()
{
    objeto.setCep(ui->le_cep1->text());
    objeto.setNumero(ui->le_num1->text());

    QString tipo;
    QString numApt = "";
    if(ui->rb_casa->isChecked()){
        tipo = "Casa";
        numApt = "-";
    }else if(ui->rb_apt->isChecked()){
        tipo = "Apartamento";
        numApt = ui->le_complemento->text();
    }else if(ui->rb_comodo->isChecked()){
        tipo = "Comodo";
        numApt = "-";
    }else if(ui->rb_outro->isChecked()){
        tipo = ui->le_outro->text();
        numApt = "-";
    }

    objeto.setTipo(tipo);
    objeto.setNumApt(numApt);

    QString energ;
    if(ui->rb_sim_ee->isChecked()){
        energ = "Sim";
    }else if(ui->rb_nao_ee->isChecked()){
        energ = "Não";
    }
    QString agua;
    if(ui->rb_sim_ae->isChecked()){
        agua = "Sim";
    }else if(ui->rb_nao_ae->isChecked()){
        agua = "Não";
    }
    QString esgo;
    if(ui->rb_sim_es->isChecked()){
        esgo = "Sim";
    }else if(ui->rb_nao_es->isChecked()){
        esgo = "Não";
    }
    QString colet;
    if(ui->rb_sim_cl->isChecked()){
        colet = "Sim";
    }else if(ui->rb_nao_cl->isChecked()){
        colet = "Não";
    }

    objeto.setEnergia(energ);
    objeto.setAgua(agua);
    objeto.setEsgoto(esgo);
    objeto.setLixo(colet);

    objeto.setQnt_pessoas(ui->le_numMembros->text().toInt());
    ui->lb_densidade->setText(objeto.getDensidade());

    objeto.setRenda(ui->le_renda->text().toDouble());
    ui->lb_gpsocial->setText(objeto.getGpSocial());
}

void EditDialog::addObjeto(Domicilio d)
{
    objeto = d;

    ui->le_cep1->setText(d.getCep());
    ui->le_num1->setText(d.getNumero());

    if(d.getTipo() == "Casa"){
        ui->rb_casa->setChecked(true);
    }else{
        if(d.getTipo() == "Apartamento"){
            ui->rb_apt->setChecked(true);
            ui->le_complemento->setText(d.getNumApt());
        }else{
            if(d.getTipo() == "Comodo"){
                ui->rb_comodo->setChecked(true);
            }else{
                ui->rb_outro->setChecked(true);
                ui->le_outro->setText(d.getTipo());
            }
        }
    }

    if(d.getEnergia() == "Sim"){
        ui->rb_sim_ee->setChecked(true);
    }else{
        ui->rb_nao_ee->setChecked(true);
    }

    if(d.getAgua() == "Sim"){
        ui->rb_sim_ae->setChecked(true);
    }else{
        ui->rb_nao_ae->setChecked(true);
    }

    if(d.getEsgoto() == "Sim"){
        ui->rb_sim_es->setChecked(true);
    }else{
        ui->rb_nao_es->setChecked(true);
    }

    if(d.getLixo() == "Sim"){
        ui->rb_sim_cl->setChecked(true);
    }else{
        ui->rb_nao_cl->setChecked(true);
    }

    ui->le_renda->setText(QString::number(d.getRenda()));
    ui->le_numMembros->setText(QString::number(d.getQnt_pessoas()));
}

Domicilio EditDialog::getObjeto() const
{
    return objeto;
}

void EditDialog::on_btn_salvar_clicked()
{
    addObjeto();
    novo = true;

    close();
}

void EditDialog::on_btn_excluir_clicked()
{
    setApagar(true);
    close();
}

void EditDialog::on_btn_cancelar_clicked()
{
    close();
}

bool EditDialog::getNovo() const
{
    return novo;
}

void EditDialog::setNovo(bool value)
{
    novo = value;
}

void EditDialog::atualizarLabel()
{
    ui->lb_densidade->setText(objeto.getDensidade());
    ui->lb_gpsocial->setText(objeto.getGpSocial());
}

bool EditDialog::getApagar() const
{
    return apagar;
}

void EditDialog::setApagar(bool value)
{
    apagar = value;
}
void EditDialog::on_le_numMembros_editingFinished()
{
    objeto.setQnt_pessoas(ui->le_numMembros->text().toInt());
    ui->lb_densidade->setText(objeto.getDensidade());
}

void EditDialog::on_le_renda_editingFinished()
{
    objeto.setRenda(ui->le_renda->text().toDouble());
    ui->lb_gpsocial->setText(objeto.getGpSocial());
}
