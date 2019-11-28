#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domicilio.h"
#include "cadastrados.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cadastrar_clicked()
{
    if(verificarFaltantes()){
        QString cep = ui->le_cep->text();
        QString num = ui->le_num->text();
        QString tipo;
        if(ui->rb_casa->isChecked()){
            tipo = "Casa";
        }else if(ui->rb_apt->isChecked()){
            tipo = "Apartamento";
        }else if(ui->rb_comodo->isChecked()){
            tipo = "Cômodo";
        }else if(ui->rb_outro->isChecked()){
            tipo = ui->le_outro->text();
        }
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
        int pessoas = ui->le_numMembros->text().toInt();
        double renda = ui->le_renda->text().toDouble();

        Domicilio domicilio(cep, num, tipo, energ, agua, esgo, colet, pessoas, renda);

        int qtd_linhas = ui->tw_tabela->rowCount();
        ui->tw_tabela->insertRow(qtd_linhas);
        inserirNaTabela(domicilio, qtd_linhas);

        QMessageBox::information(this,"Cadastro","Cadastro realizado com sucesso!");

        ui->le_cep->clear();
        ui->le_num->clear();
        ui->le_outro->clear();
        ui->le_renda->clear();
        ui->le_numMembros->clear();
        ui->le_cep->setFocus();

        //.inserirDomicilio(domicilio);

    }else{
        QMessageBox::critical(this,"Erro","Dados Incompletos, cadastro não realizado!");

    }

}

void MainWindow::inserirNaTabela(Domicilio c, int linha)
{
    ui->tw_tabela->setItem(linha,0, new QTableWidgetItem(c.getCep()));
    ui->tw_tabela->setColumnWidth(0,60);
    ui->tw_tabela->setItem(linha,1, new QTableWidgetItem(c.getNumero()));
    ui->tw_tabela->setColumnWidth(1,20);
    ui->tw_tabela->setItem(linha,2, new QTableWidgetItem(c.getTipo()));
    ui->tw_tabela->setColumnWidth(2,60);
    ui->tw_tabela->setItem(linha,3, new QTableWidgetItem(QString::number(c.getQnt_pessoas())));
    ui->tw_tabela->setColumnWidth(3,110);
    ui->tw_tabela->setItem(linha,4, new QTableWidgetItem(c.definirDensidade()));
    ui->tw_tabela->setColumnWidth(4,150);
    ui->tw_tabela->setItem(linha,5, new QTableWidgetItem("R$"+QString::number(c.getRenda())));
    ui->tw_tabela->setColumnWidth(5,100);
    ui->tw_tabela->setItem(linha,6, new QTableWidgetItem(c.definirGrupoSocial()));
    ui->tw_tabela->setColumnWidth(6,80);

    ui->tw_tabela->verticalHeader()->setVisible(false);
}

bool MainWindow::verificarFaltantes()
{
    if((ui->le_cep->text().size() != 0)
        and (ui->le_num->text().size() != 0)
        and (ui->rb_casa->isChecked() or ui->rb_apt->isChecked() or ui->rb_comodo->isChecked() or (ui->rb_outro->isChecked() and ui->le_outro->text().size() != 0))
        and (ui->rb_sim_ee->isChecked() or ui->rb_nao_ee->isChecked())
        and (ui->rb_sim_ae->isChecked() or ui->rb_nao_ae->isChecked())
        and (ui->rb_sim_es->isChecked() or ui->rb_nao_es->isChecked())
        and (ui->rb_sim_cl->isChecked() or ui->rb_nao_cl->isChecked())
        and (ui->le_numMembros->text().size() != 0)
        and (ui->le_renda->text().size() != 0))
    {
        return true;
    }else{
        return false;
    }
}

void MainWindow::on_btn_maps_clicked()
{
    QUrl url = QUrl("https://www.google.com.br/maps/");
    QDesktopServices::openUrl(url);

}
