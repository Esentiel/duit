#include "eventsmodel.h"

EventsModel::EventsModel(QObject *parent):
    QAbstractListModel(parent)
{
    //test items
    eventsList.push_back(ScheduledEvent("Test1"));
    eventsList.push_back(ScheduledEvent("Test2"));
    eventsList.push_back(ScheduledEvent("Test3"));
}

int EventsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return eventsList.size();
}

QVariant EventsModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return eventsList.at(index.row()).getEventName();
    }else
    {
        return QVariant();
    }
}

Qt::ItemFlags EventsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool EventsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole && index.isValid()) {
       int row = index.row();
       eventsList.replace(row, ScheduledEvent(value.toString()));
       emit(dataChanged(index, index));

       return true;
   }

   return false;
}

void EventsModel::addEntry(const QString &name)
{
    insertRows(rowCount(), 1, QModelIndex());
    QModelIndex myIndex = index(rowCount()-1);
    setData(myIndex, QVariant(name), Qt::EditRole);
}

const QMap<QString, QVariant> & EventsModel::getEventParams(int row) const noexcept
{
    return eventsList.at(row).getParams();
}

void EventsModel::setEventParams(int row, const QMap<QString, QVariant> & params)
{
    ScheduledEvent tempEvent = eventsList.at(row);
    tempEvent.setParams(params);
    eventsList.replace(row, tempEvent);
}

bool EventsModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        eventsList.insert(position, ScheduledEvent());
    }

    endInsertRows();
    return true;
}

bool EventsModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        eventsList.removeAt(position);
    }

    endRemoveRows();
    return true;
}
