#include "eventsmodel.h"

EventsModel::EventsModel(QObject *parent):
    QAbstractListModel(parent)
{
    //test items
    m_list.push_back(ScheduledEvent());
    m_list.push_back(ScheduledEvent());
    m_list.push_back(ScheduledEvent());
}

int EventsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_list.size();
}

QVariant EventsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_list.at(index.row()).getName();
    }else
    {
        return QVariant();
    }
}
