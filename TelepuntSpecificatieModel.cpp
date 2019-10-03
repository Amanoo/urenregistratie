#include "TelepuntSpecificatieModel.hpp"

#include <QModelIndex>
#include <QTime>

TelepuntSpecificatieModel::TelepuntSpecificatieModel()
{

}

int TelepuntSpecificatieModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0; // Items do not have subitems

    return mSpecItems.size()+1;
}

int TelepuntSpecificatieModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return 2;
}

QVariant TelepuntSpecificatieModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0)
        return QVariant{};
    if(index.row() > mSpecItems.size())
        return QVariant{};
    if(index.column() < 0 || index.column() > 2)
        return QVariant{};

    switch (role) {
        case Qt::DisplayRole:
        if(index.row() < mSpecItems.size()) {
            switch(index.column()) {
            case 0:
                return mSpecItems.at(index.row()).first;
            case 1:
                return mSpecItems.at(index.row()).second;
            default:
                return QVariant{};
            }
        } else {
            return "<Toevoegen>";
        }
    case Qt::EditRole:
        if(index.row() < mSpecItems.size()) {
            switch(index.column()) {
            case 0:
                return mSpecItems.at(index.row()).first;
            case 1:
                return mSpecItems.at(index.row()).second;
            default:
                return QVariant{};
            }
        } else {
            return "";
        }
    }

    return QVariant{};
}

bool TelepuntSpecificatieModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() < 0 || index.row() > mSpecItems.size() ||
            index.column() < 0 || index.column() > 2)
        return false;

    if(role == Qt::EditRole) {
        if(index.row() < mSpecItems.size()) {
            switch(index.column()) {
            case 0:
                mSpecItems[index.row()].first = value.toString();
                emit dataChanged(index, index);
                return true;
            case 1:
                mSpecItems[index.row()].second = value.toTime();
                emit dataChanged(index, index);
                return true;
            }
        } else {
            QPair<QString, QTime> newData = qMakePair(QString(), QTime());

            switch(index.column()) {
            case 0:
                newData.first = value.toString();
                beginInsertRows(QModelIndex(), index.row(), index.row());
                mSpecItems.append(newData);
                endInsertRows();
                return true;
            case 1:
                newData.second = value.toTime();
                beginInsertRows(QModelIndex(), index.row(), index.row());
                mSpecItems.append(newData);
                endInsertRows();
                return true;
            }
        }
    }
    return false;
}

QVariant TelepuntSpecificatieModel::headerData(int row, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal) {
        if(role == Qt::DisplayRole) {
            switch(row) {
            case 0:
                return "Omschrijving";
            case 1:
                return "Tijd";
            }
        }
    }

    return QVariant{};
}

Qt::ItemFlags TelepuntSpecificatieModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
