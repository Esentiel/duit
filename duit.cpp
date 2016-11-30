#include "duit.h"
#include "ui_duit.h"
#include "addeditdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("Duit - Make every-day events scheduled");
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
        eventsModel->addEntry(addDialogWindow.getNameValue(), addDialogWindow.getParams());
    }
}

void MainWindow::on_actionEditEvent_triggered()
{
    QModelIndex currentIndex = ui->eventsView->currentIndex();
    const int row = currentIndex.row();
    if (currentIndex.isValid())
    {
        AddEditDialog editDialogWindow;
        editDialogWindow.setWindowTitle("Edit "+eventsModel->data(currentIndex).toString());
        editDialogWindow.setNameValue(eventsModel->data(currentIndex).toString());
        editDialogWindow.setParams(eventsModel->getEventParams(row));
        editDialogWindow.setModal(true);
        int dialogCode = editDialogWindow.exec();

        if(dialogCode == QDialog::Accepted)
        {
            QString theName =  editDialogWindow.getNameValue();
            auto eventParams = editDialogWindow.getParams();
            eventsModel->setData(currentIndex,theName,Qt::EditRole);
            eventsModel->setEventParams(row,eventParams);
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
