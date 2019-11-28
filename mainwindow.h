#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QDesktopServices>
#include <QVector>
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

private:
    Ui::MainWindow *ui;
    void inserirNaTabela(Domicilio c, int linha);
    bool verificarFaltantes();
};

#endif // MAINWINDOW_H
