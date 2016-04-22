#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDialog;
}

class AddEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDialog(QWidget *parent = 0);
    ~AddEditDialog();
    const QString& getNameValue() const noexcept;

private slots:
    void on_cancelButton_clicked();
    void on_nameValue_editingFinished();
    void on_okButton_clicked();

private:
    Ui::AddEditDialog *ui;
    QString nameValue;
};

#endif // ADDEDITDIALOG_H
