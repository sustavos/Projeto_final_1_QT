#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tw_tabela->setColumnWidth(0,110);
    ui->tw_tabela->setColumnWidth(1,70);
    ui->tw_tabela->setColumnWidth(2,110);
    ui->tw_tabela->setColumnWidth(3,100);

    QStringList cabecalhos = {"CEP", "Nº", "Tipo", "Complemento"};
    ui->tw_tabela->setHorizontalHeaderLabels(cabecalhos);
    ui->tw_tabela->verticalHeader()->setVisible(false);
    ui->tw_tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tw_tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
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

        Domicilio domicilio(cep, num, tipo, numApt, energ, agua, esgo, colet, pessoas, renda);

        if(cadastrados.VerificarExistencia(domicilio)){

            QMessageBox::critical(this,"Erro","O domicílio já foi cadastrado.");

        }else{

            int qtd_linhas = ui->tw_tabela->rowCount();
            ui->tw_tabela->insertRow(qtd_linhas);
            inserirNaTabela(domicilio, qtd_linhas);


            QMessageBox::information(this,"Cadastro","Cadastro realizado com sucesso!");

            cadastrados.inserirDomicilio(domicilio);

            atualizarEstatisticas();
        }

    }else{

        QMessageBox::critical(this,"Erro","Dados Incompletos, cadastro não realizado!");
    }

    ui->le_cep->clear();
    ui->le_num->clear();
    ui->le_outro->clear();
    ui->le_renda->clear();
    ui->le_numMembros->clear();
    ui->le_complemento->clear();
    ui->rb_casa->setAutoExclusive(false);
    ui->rb_casa->setChecked(false);
    ui->rb_casa->setAutoExclusive(true);
    ui->rb_apt->setAutoExclusive(false);
    ui->rb_apt->setChecked(false);
    ui->rb_apt->setAutoExclusive(true);
    ui->rb_comodo->setAutoExclusive(false);
    ui->rb_comodo->setChecked(false);
    ui->rb_comodo->setAutoExclusive(true);
    ui->rb_outro->setAutoExclusive(false);
    ui->rb_outro->setChecked(false);
    ui->rb_outro->setAutoExclusive(true);
    ui->rb_sim_ae->setAutoExclusive(false);
    ui->rb_sim_ae->setChecked(false);
    ui->rb_sim_ae->setAutoExclusive(true);
    ui->rb_sim_cl->setAutoExclusive(false);
    ui->rb_sim_cl->setChecked(false);
    ui->rb_sim_cl->setAutoExclusive(true);
    ui->rb_sim_ee->setAutoExclusive(false);
    ui->rb_sim_ee->setChecked(false);
    ui->rb_sim_ee->setAutoExclusive(true);
    ui->rb_sim_es->setAutoExclusive(false);
    ui->rb_sim_es->setChecked(false);
    ui->rb_sim_es->setAutoExclusive(true);
    ui->rb_nao_ae->setAutoExclusive(false);
    ui->rb_nao_ae->setChecked(false);
    ui->rb_nao_ae->setAutoExclusive(true);
    ui->rb_nao_cl->setAutoExclusive(false);
    ui->rb_nao_cl->setChecked(false);
    ui->rb_nao_cl->setAutoExclusive(true);
    ui->rb_nao_ee->setAutoExclusive(false);
    ui->rb_nao_ee->setChecked(false);
    ui->rb_nao_ee->setAutoExclusive(true);
    ui->rb_nao_es->setAutoExclusive(false);
    ui->rb_nao_es->setChecked(false);
    ui->rb_nao_es->setAutoExclusive(true);
    ui->le_cep->setFocus();

}

void MainWindow::inserirNaTabela(Domicilio c, int linha)
{
    ui->tw_tabela->setItem(linha,0, new QTableWidgetItem(c.getCep()));
    ui->tw_tabela->setItem(linha,1, new QTableWidgetItem(c.getNumero()));
    ui->tw_tabela->setItem(linha,2, new QTableWidgetItem(c.getTipo()));
    ui->tw_tabela->setItem(linha,3, new QTableWidgetItem(c.getNumApt()));

}

bool MainWindow::verificarFaltantes()
{
    if((ui->le_cep->text().size() != 0)
        and (ui->le_num->text().size() != 0)
        and (ui->rb_casa->isChecked() or (ui->rb_apt->isChecked() and ui->le_complemento->text().size() != 0) or ui->rb_comodo->isChecked() or (ui->rb_outro->isChecked() and ui->le_outro->text().size() != 0))
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

void MainWindow::atualizarEstatisticas()
{
    ui->tb_totalCadastrados->setText(QString::number(cadastrados.size()));

    ui->tb_casa->setText(QString::number(cadastrados.getCasasCadastradas()));
    ui->tb_apt->setText(QString::number(cadastrados.getAptCadastrados()));
    ui->tb_comodo->setText(QString::number(cadastrados.getComodosCadastrados()));
    ui->tb_outro->setText(QString::number(cadastrados.getOutros()));

    ui->tb_semEnergia->setText(QString::number(cadastrados.getSemEnergia()));
    ui->tb_semAgua->setText(QString::number(cadastrados.getSemAgua()));
    ui->tb_semEsgoto->setText(QString::number(cadastrados.getSemEsgoto()));
    ui->tb_semLixo->setText(QString::number(cadastrados.getSemLixo()));

    ui->tb_maiorRenda->setText("R$" + QString::number(cadastrados.getMaiorRenda()));
    ui->tb_menorRenda->setText("R$" + QString::number(cadastrados.getMenorRenda()));
    ui->tb_rendaMedia->setText("R$" + QString::number(cadastrados.getRendaMedia()));

    ui->tb_domMaisPop->setText(QString::number(cadastrados.getMaiorPop()));
    ui->tb_domMenosPop->setText(QString::number(cadastrados.getMenorPop()));
    ui->tb_medPop->setText(QString::number(cadastrados.getMediaPop()));
}

void MainWindow::on_btn_maps_clicked()
{
    QUrl url = QUrl("https://www.google.com.br/maps/");
    QDesktopServices::openUrl(url);

}

void MainWindow::on_btn_ordenarCEP_clicked()
{
    cadastrados.ordenarCEP();
    ui->tw_tabela->clearContents();
    for(int i=0; i < cadastrados.size(); i++){
        inserirNaTabela(cadastrados[i],i);
    }
}

void MainWindow::on_btn_ordenarNUM_clicked()
{
    cadastrados.ordernarNum();
    ui->tw_tabela->clearContents();
    for(int i=0; i < cadastrados.size(); i++){
        inserirNaTabela(cadastrados[i],i);
    }
}


void MainWindow::on_actionSalvar_Arquivo_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo","","*.csv");

    if(cadastrados.salvarDados(filename) == true){
        QMessageBox::information(this,"Salvar Arquivo","Arquivo salvo com sucesso!");
    }else{
        QMessageBox::critical(this,"Erro", "Não foi possível salvar o arquivo.");
    }
}

void MainWindow::on_actionCarregar_Arquivo_triggered()
{
    cadastrados.limparVec();

    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Carregar Arquivo", "", "*.csv");

    if(cadastrados.carregarDados(filename)){
        QMessageBox::critical(this,"Erro","Arquivo já carregado");
    }else{

        ui->tw_tabela->clearContents();
        int qtdLinhas = ui->tw_tabela->rowCount();

        for(int i = 0; i < qtdLinhas ; i++){
            ui->tw_tabela->removeRow(0);
        }

        for(int i = 0; i < cadastrados.size(); i++){
            ui->tw_tabela->insertRow(i);
            inserirNaTabela(cadastrados[i],i);
        }

        QMessageBox::information(this,"Carregar Arquivo","Arquivo carregado com sucesso!");

    }

    atualizarEstatisticas();
}

void MainWindow::on_tw_tabela_cellDoubleClicked(int row, int column)
{
    ui->tw_tabela->setRowCount(0);
    EditDialog act;

    act.addObjeto(cadastrados[row]);

    act.atualizarLabel();
    act.setWindowTitle("Editar Domicílio");
    act.setModal(true);
    act.exec();

    column = 0;

    atualizarTabela();

    if(act.getApagar())
    {
        cadastrados.erase(row);
        atualizarTabela();
    }

    if(act.getNovo())
    {
        cadastrados.setObjeto(row, act.getObjeto());
        atualizarTabela();
    }

    atualizarEstatisticas();
}

void MainWindow::atualizarTabela()
{
    ui->tw_tabela->setRowCount(0);

    for(auto print : cadastrados.getLista()){

        int linha = ui->tw_tabela->rowCount();
        ui->tw_tabela->insertRow(linha);

        ui->tw_tabela->setItem(linha,0, new QTableWidgetItem(print.getCep()));
        ui->tw_tabela->setItem(linha,1, new QTableWidgetItem(print.getNumero()));
        ui->tw_tabela->setItem(linha,2, new QTableWidgetItem(print.getTipo()));
        ui->tw_tabela->setItem(linha,3, new QTableWidgetItem(print.getNumApt()));

    }
}
