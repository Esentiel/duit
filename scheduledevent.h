#ifndef SCHEDULEDEVENT_H
#define SCHEDULEDEVENT_H
#include <QString>
#include <QMetaType>



class ScheduledEvent  
{
public:
    ScheduledEvent();
    ScheduledEvent(const ScheduledEvent &copy);
    ~ScheduledEvent();
    QString getName() const noexcept;
private:
    QString m_name;
};

Q_DECLARE_METATYPE(ScheduledEvent)


#endif // SCHEDULEDEVENT_H
