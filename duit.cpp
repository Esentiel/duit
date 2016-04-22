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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eventsModel;
}

void MainWindow::on_actionAddEvent_triggered()
{
    AddEditDialog addDialogWindow;
    addDialogWindow.setModal(true);
    //connect(addDialogWindow, SIGNAL(accepted()), this, SLOT());
    int dialogCode = addDialogWindow.exec();

    if(dialogCode == QDialog::Accepted)
    {
        QString theName =  addDialogWindow.getNameValue();
//        bool state = eventsModel->insertRow(eventsModel->rowCount());
//        size_t size = eventsModel->rowCount();
//        QModelIndex index = eventsModel->index(size);
//        eventsModel->setData(index,theName,Qt::EditRole);
        eventsModel->addEntry(theName);
    }
}
