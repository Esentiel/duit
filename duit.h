#ifndef DUIT_H
#define DUIT_H

#include <QMainWindow>
#include "eventsmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAddEvent_triggered();
    void on_actionEditEvent_triggered();
    void on_actionDeleteEvent_triggered();
    void on_actionExit_triggered();
    void on_eventsView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    EventsModel * eventsModel;
};

#endif // DUIT_H
