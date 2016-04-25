#include "scheduledevent.h"
#include <QMessageBox>
#include <QObject>
#include <algorithm>
#include <iostream>

ScheduledEvent::ScheduledEvent()
{
    eventHandler = nullptr;
    timer = std::make_unique<QTimer>(new QTimer(0));
}

ScheduledEvent::ScheduledEvent(const QString& name)
{
    eventName = name;
    eventHandler = nullptr;
    timer = std::make_unique<QTimer>(new QTimer(0));
}

ScheduledEvent::ScheduledEvent(const ScheduledEvent &copy)
{
    eventName = copy.getEventName();
    eventHandler = std::move(copy.getEventHandler());
    eventParameters = copy.getParams();
    timer = std::move(copy.getTimer());
}

ScheduledEvent& ScheduledEvent::operator=(const ScheduledEvent& copy)
{
    eventName = copy.getEventName();
    eventHandler = std::move(copy.getEventHandler());
    eventParameters = copy.getParams();
    timer = std::move(copy.getTimer());

    return *this;
}

ScheduledEvent::~ScheduledEvent()
{

}

const QString& ScheduledEvent::getEventName() const noexcept
{
    return eventName;
}

void ScheduledEvent::setEventName(const QString &name)
{
    eventName = name;
}

const QMap<QString, QVariant> & ScheduledEvent::getParams() const noexcept
{
    return eventParameters;
}

void ScheduledEvent::setParams(const QMap<QString, QVariant> &params)
{
    eventParameters = params;
    eventHandler = std::make_unique<EventHandler>(new EventHandler(eventName));

    if (eventHandler && timer)
    {
        QObject::connect(timer.get(), SIGNAL(timeout()), this->eventHandler.get(), SLOT(fireEvent()));
        timer->start(params["repeatValue"].toDouble() * 1000 );
    }
}

std::unique_ptr<EventHandler> ScheduledEvent::getEventHandler() const
{
    return std::move(eventHandler);
}

std::unique_ptr<QTimer> ScheduledEvent::getTimer() const
{
    return std::move(timer);
}
