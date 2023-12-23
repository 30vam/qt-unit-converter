#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>

class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);
    //Getters and setters
    QStandardItemModel *getModel();

private:
    QStandardItemModel *m_model;

signals:
    void modelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
};

#endif // DATAMODEL_H