//
// Created by Chrystalkey on 09.08.2018.
//

#include <QtSql/QSqlQuery>
#include <QFileInfo>
#include <QFile>
#include "databaseaccess.h"
#include "flauscharchivar_global.h"

DatabaseAccess::DatabaseAccess(const QString &topLevelDirectory):QObject(nullptr), topLevelDirectory(topLevelDirectory){
    QFile file(":/dbStructure.sql");
    file.open(QFile::ReadOnly);
    dbStructure = normalizeSqlFile(file.readAll());
    file.close();
    file.setFileName(":/data.sql");
    file.open(QFile::ReadOnly);
    dbInitProperties = normalizeSqlFile(file.readAll());
    file.close();
    if(QFile::exists(this->topLevelDirectory.absoluteFilePath("main.db"))){
        sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
        sqlDatabase.setDatabaseName(this->topLevelDirectory.absoluteFilePath("main.db"));
        sqlDatabase.open();
        QSqlQuery query;
        for(QString &i: dbStructure){
            query.exec(i);
        }
        for(QString &i: dbInitProperties){
            query.exec(i);
        }
    }else{
        sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
        sqlDatabase.setDatabaseName(this->topLevelDirectory.absoluteFilePath("main.db"));
        sqlDatabase.open();
    }
}

bool DatabaseAccess::addFileToInventory(const QString &filePath) {
    QFile file(filePath);
    QFileInfo info(file);
    file.open(QFile::ReadOnly);
}