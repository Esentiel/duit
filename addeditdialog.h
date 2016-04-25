#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>
#include <QString>
#include <QVariant>
#include <QMap>

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
    void setNameValue(const QString &name);
    const QMap<QString, QVariant>& getParams() const noexcept;
    void setParams(const QMap<QString, QVariant> &params);

private slots:
    void on_cancelButton_clicked();
    void on_nameValue_editingFinished();
    void on_repeatValue_editingFinished();
    void on_okButton_clicked();
    QString getRepeatValue() const noexcept;
    void setRepeatValue(const QString &repeatVal);

private:
    Ui::AddEditDialog *ui;
    QString nameValue;
    QMap<QString, QVariant> eventParams;
};

#endif // ADDEDITDIALOG_H
