#include "scheduledevent.h"

ScheduledEvent::ScheduledEvent()
{
    m_name = "Test!";
}

ScheduledEvent::ScheduledEvent(const ScheduledEvent &copy)
{
    this->m_name = copy.getName();
}

ScheduledEvent::~ScheduledEvent()
{

}

QString ScheduledEvent::getName() const noexcept
{
    return m_name;
}
