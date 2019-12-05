#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QDebug>
#include <QDesktopServices>
#include <QVector>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "domicilio.h"
#include "cadastrados.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_cadastrar_clicked();
    void on_btn_maps_clicked();
    void on_btn_ordenarCEP_clicked();
    void on_btn_ordenarNUM_clicked();

    void on_actionSalvar_Arquivo_triggered();

    void on_actionCarregar_Arquivo_triggered();

private:
    Ui::MainWindow *ui;

    void inserirNaTabela(Domicilio c, int linha);
    bool verificarFaltantes();
    void atualizarEstatisticas();

    Cadastrados cadastrados;
};

#endif // MAINWINDOW_H
