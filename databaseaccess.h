//
// Created by Chrystalkey on 09.08.2018.
//

#ifndef FLAUSCHARCHIVAR_DATABASEACCESS_H
#define FLAUSCHARCHIVAR_DATABASEACCESS_H

#include <QObject>
#include <QtCore/QString>
#include <QtSql/QSqlDatabase>
#include <QtCore/QDir>

class DatabaseAccess :public QObject {
public:
    DatabaseAccess(const QString& topLevelDirectory = "F:/experimental_archive/");
    ~DatabaseAccess();

    quint64 getTargetIdByFileName(const QString &fileName);

    quint64 getTargetIdByFileChecksum(const QString &fileName);
    void addTargetProperty(quint64 id, const QString &property, const QString &propertyState);
    QList<QVariant> getTargetProperty(quint64 id, const QString& property);

public slots:
    bool addFileToInventory(const QString& filePath);
    bool addNoteToInventory(const QString &note);
private:
    QSqlDatabase sqlDatabase;
    QDir topLevelDirectory;
    QStringList dbStructure = QStringList();
    QStringList dbInitProperties = QStringList();
};


#endif //FLAUSCHARCHIVAR_DATABASEACCESS_H
