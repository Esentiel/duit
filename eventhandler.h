#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject
{
    Q_OBJECT
public:
    explicit EventHandler(QObject *parent = 0);
    EventHandler(const QString &message);
    EventHandler(const EventHandler &copy);
    EventHandler& operator=(const EventHandler& copy);
    QString messageText;

signals:

public slots:
    void fireEvent();
};

#endif // EVENTHANDLER_H
