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

private:
    Ui::MainWindow *ui;
    EventsModel * eventsModel;
};

#endif // DUIT_H
