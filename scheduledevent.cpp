#include "scheduledevent.h"

ScheduledEvent::ScheduledEvent()
{

}

ScheduledEvent::ScheduledEvent(const QString& name)
{
    eventName = name;
}

ScheduledEvent::ScheduledEvent(const ScheduledEvent &copy)
{
    eventName = copy.getEventName();
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
}
