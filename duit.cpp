#include "duit.h"
#include "ui_duit.h"

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
