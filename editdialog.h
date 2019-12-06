#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "domicilio.h"
#include "cadastrados.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();


    void addObjeto();
    void addObjeto(Domicilio d);
    Domicilio getObjeto() const;

    bool getApagar() const;
    void setApagar(bool value);

    bool getNovo() const;
    void setNovo(bool value);

private slots:

    void on_btn_salvar_clicked();
    void on_btn_excluir_clicked();
    void on_btn_cancelar_clicked();

private:
    Ui::EditDialog *ui;

    Domicilio objeto;
    bool novo;
    bool apagar;
};

#endif // EDITDIALOG_H
