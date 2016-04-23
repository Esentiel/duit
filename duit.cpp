#include "duit.h"
#include "ui_duit.h"
#include "addeditdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eventsModel = new EventsModel(0);
    ui->eventsView->setModel(eventsModel);
    ui->eventsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eventsModel;
}

void MainWindow::on_eventsView_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    on_actionEditEvent_triggered();
}

void MainWindow::on_actionAddEvent_triggered()
{
    AddEditDialog addDialogWindow;
    addDialogWindow.setWindowTitle("Add New Event");
    addDialogWindow.setModal(true);
    int dialogCode = addDialogWindow.exec();

    if(dialogCode == QDialog::Accepted)
    {
        eventsModel->addEntry(addDialogWindow.getNameValue());
    }
}

void MainWindow::on_actionEditEvent_triggered()
{
    QModelIndex currentIndex = ui->eventsView->currentIndex();
    if (currentIndex.isValid())
    {
        AddEditDialog addDialogWindow;
        addDialogWindow.setWindowTitle("Edit "+eventsModel->data(currentIndex).toString());
        addDialogWindow.setNameValue(eventsModel->data(currentIndex).toString());
        addDialogWindow.setModal(true);
        int dialogCode = addDialogWindow.exec();

        if(dialogCode == QDialog::Accepted)
        {
            QString theName =  addDialogWindow.getNameValue();

            eventsModel->setData(currentIndex,theName,Qt::EditRole);
        }
    }
}

void MainWindow::on_actionDeleteEvent_triggered()
{
    const int position = ui->eventsView->currentIndex().row();
    eventsModel->removeRows(position, 1, QModelIndex());
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
