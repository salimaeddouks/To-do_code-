#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::get()const

{

    auto date=ui->dateEdit->date();
    auto a="      ";
    return ui->lineEdit->text() +a+ ui->comboBox->currentText() +a+ date.toString();

}






