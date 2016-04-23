#include "addeditdialog.h"
#include "ui_addeditdialog.h"

AddEditDialog::AddEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDialog)
{
    ui->setupUi(this);
}

AddEditDialog::~AddEditDialog()
{
    delete ui;
}

void AddEditDialog::on_cancelButton_clicked()
{
    this->reject();
}

void AddEditDialog::on_okButton_clicked()
{
    this->accept();
}

void AddEditDialog::on_nameValue_editingFinished()
{
    nameValue = ui->nameValue->text();
}

const QString & AddEditDialog::getNameValue() const noexcept
{
    return nameValue;
}

void AddEditDialog::setNameValue(const QString &name)
{
   nameValue = name;
   ui->nameValue->setText(name);

}
