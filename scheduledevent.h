#ifndef SCHEDULEDEVENT_H
#define SCHEDULEDEVENT_H
#include <QString>
#include <QMap>
#include <QVariant>
#include <QMetaType>
#include "eventhandler.h"
#include <memory>
#include <QTimer>


class ScheduledEvent
{
public:
    ScheduledEvent();
    ScheduledEvent(const QString& name);
    ScheduledEvent(const ScheduledEvent &copy);
    ScheduledEvent& operator=(const ScheduledEvent& copy);
    ~ScheduledEvent();
    const QString& getEventName() const noexcept;
    void setEventName(const QString &name);
    const QMap<QString, QVariant> & getParams() const noexcept;
    void setParams(const QMap<QString, QVariant> &params);
    std::unique_ptr<EventHandler> getEventHandler() const;
    std::unique_ptr<QTimer> getTimer() const;
private:
    QString eventName;
    QMap<QString, QVariant> eventParameters;
    mutable std::unique_ptr<EventHandler> eventHandler;
    mutable std::unique_ptr<QTimer> timer;

};

Q_DECLARE_METATYPE(ScheduledEvent)


#endif // SCHEDULEDEVENT_H
