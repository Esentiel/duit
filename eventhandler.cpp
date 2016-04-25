#include "eventhandler.h"
#include <QMessageBox>

EventHandler::EventHandler(QObject *parent) : QObject(parent)
{

}

EventHandler::EventHandler(const QString &message)
    : messageText(message)
{

}

EventHandler::EventHandler(const EventHandler &copy)
{
    messageText = copy.messageText;
}

EventHandler& EventHandler::operator=(const EventHandler& copy)
{
    messageText = copy.messageText;

    return *this;
}

void EventHandler::fireEvent()
{
    QMessageBox msgBox;
    msgBox.setText(messageText);
    msgBox.exec();
}
