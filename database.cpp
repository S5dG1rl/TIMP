#include "database.h"

DataBase* DataBase::p_instance = nullptr;
DatabaseDestroyer DataBase::destroyer;

DataBase::DataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Database.db");
    
    if (!db.open()) {
        qCritical() << "Error: Failed to open database:" << db.lastError().text();
        return;
    }
    
    // Enable foreign keys if needed
    QSqlQuery query(db);
    if (!query.exec("PRAGMA foreign_keys = ON")) {
        qWarning() << "Failed to enable foreign keys:" << query.lastError().text();
    }
}

bool DataBase::createTable(){
    QSqlQuery query(db);
    
    // Check if table already exists
    if (db.tables().contains("users")) {
        qDebug() << "Table 'users' already exists";
        return true;
    }
    
    // Create the table with a default sockid of -1
    QString createTableSQL = 
        "CREATE TABLE users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "login TEXT NOT NULL UNIQUE, "
        "password TEXT NOT NULL, "
        "email TEXT NOT NULL UNIQUE, "
        "stat INTEGER DEFAULT 0, "
        "sockid INTEGER NOT NULL DEFAULT -1"
        ")";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "Failed to create table:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "Table 'users' created successfully";
    return true;
}

DataBase::~DataBase(){
    db.close();
}

DataBase& DataBase::getInstance(){
    if(!p_instance){
        p_instance = new DataBase();
        p_instance->createTable();
    }
    return *p_instance;
}

QSqlDatabase& DataBase::getDatabase(){
    return db;
}

DatabaseDestroyer::~DatabaseDestroyer() {
    delete p_instance;
}

void DatabaseDestroyer::initialize(DataBase *p) {
    p_instance = p;
}

QStringList DataBase::queryToDatabase(QStringList src){
    QSqlQuery query(db);
    query.prepare(src[0]);
    int i = 1;
    while(i < src.size())
    {
        query.bindValue(src[i], src[i+1]);
        i+=2;
    }

    QStringList res;
    if(src[0].contains("SELECT")){
        // qDebug() << query.exec();
        // qDebug() << query.first();
        if(query.exec() && query.first()){
            res.append("found");
            return res;
        }
    }
    else{
        if(query.exec()){
            res.append("ok");
            return res;
        }
    }
    return res;
}
