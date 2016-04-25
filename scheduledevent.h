#ifndef SCHEDULEDEVENT_H
#define SCHEDULEDEVENT_H
#include <QString>
#include <QMap>
#include <QVariant>
#include <QMetaType>



class ScheduledEvent  
{
public:
    ScheduledEvent();
    ScheduledEvent(const QString& name);
    ScheduledEvent(const ScheduledEvent &copy);
    ~ScheduledEvent();
    const QString& getEventName() const noexcept;
    void setEventName(const QString &name);
    const QMap<QString, QVariant> & getParams() const noexcept;
    void setParams(const QMap<QString, QVariant> &params);
private:
    QString eventName;
    QMap<QString, QVariant> eventParameters;
};

Q_DECLARE_METATYPE(ScheduledEvent)


#endif // SCHEDULEDEVENT_H
