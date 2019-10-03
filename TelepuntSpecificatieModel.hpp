#ifndef TELEPUNTSPECIFICATIEMODEL_HPP
#define TELEPUNTSPECIFICATIEMODEL_HPP

#include <QAbstractTableModel>



class TelepuntSpecificatieModel : public QAbstractTableModel
{
    QList<QPair<QString,QTime>> mSpecItems;

public:
    TelepuntSpecificatieModel();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant headerData(int row, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // TELEPUNTSPECIFICATIEMODEL_HPP
