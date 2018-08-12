#include <iostream>
#include <QFile>
#include "flauscharchivar_global.h"

int main() {
    Q_INIT_RESOURCE(resource_file);
    QFile file(":/dbStructure.sql");
    file.open(QFile::ReadOnly);
    normalizeSqlFile(QString(file.readAll()));
    return 0;
}

QStringList normalizeSqlFile(const QString &in){
    QStringList sqlBatch;
    QString temp = in;
    //comments
    temp = temp.remove(QRegExp("--[^\\r\\n]*"));
    //qDebug() << temp;
    //remove linebreaks
    sqlBatch = temp.split(";",QString::SkipEmptyParts);
    for(QString &statement:sqlBatch){
        if(statement.size() < 10){
            sqlBatch.removeAll(statement);
            continue;
        }
        statement = statement.remove('\n').remove('\t').append(';');
        //std::cerr <<"|" << statement.toStdString() << "\n";
    }
    return sqlBatch;
}