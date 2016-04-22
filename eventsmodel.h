#ifndef EVENTSMODEL_H
#define EVENTSMODEL_H
#include <QAbstractListModel>
#include "scheduledevent.h"

class EventsModel : public QAbstractListModel
{
public:
    EventsModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    QList<ScheduledEvent> m_list;
};

#endif // EVENTSMODEL_H
