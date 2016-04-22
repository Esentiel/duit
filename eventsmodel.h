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
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void addEntry(const QString &name);
    bool insertRows(int position, int rows, const QModelIndex &index) override;
private:
    QList<ScheduledEvent> eventsList;
};

#endif // EVENTSMODEL_H
