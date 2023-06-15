#include "SQLite.h"

// Private constructor so that no objects can be created.
SQLite::SQLite() {}
SQLite::~SQLite () {
    sqlite3_close(db);
    delete(_Database);   
}

int SQLite::callback(void *data, int argc, char **argv, char **azColName) {

    for(int i = 0; i < argc; i++)
        _BackResults.push_back(argv[i] ? argv[i] : "0");
    return 0;
}

// Create or return a pointer to this object designed with the Singleton pattern
SQLite* SQLite::CreateDatabase() {

    if (!_Database)
        _Database = new SQLite();
    return _Database;
}

void SQLite::SetPathDatabaseFile (const char* FileName) {
    _GlobalPath = FileName;
}

bool SQLite::OpenDatabase () { 

    int rc = sqlite3_open(_GlobalPath, &db);

    if( rc ) {
    cout << "Can't open database: " << sqlite3_errmsg(db);
    return true;
    }
    else
    //cout << "Opened database successfully\n";
    return false;
}

void SQLite::CloseDatabase () {
    sqlite3_close(db);
}

void SQLite::DeletePointerDatabase () {
    delete(_Database);
}

// Send Only 
bool SQLite::ExecuteQuery (string SQLQuery) {

    char* ErrorMsg;
    int ReturnStatus;

    ReturnStatus = sqlite3_exec(db, SQLQuery.c_str(), NULL, 0, &ErrorMsg);
    
    if( ReturnStatus != SQLITE_OK ){
    cout << "\nSQL error: " << ErrorMsg << endl;
        sqlite3_free(ErrorMsg);
        return true;
    } 
    else {
        return false;
    }
} 

// Back Only One Record
bool SQLite::ExecuteQuery (string SQLQuery, vector<string>& BackResults) {

    char* ErrorMsg;
    int ReturnStatus;
    _BackResults.clear();
    ReturnStatus = sqlite3_exec(db, SQLQuery.c_str(), callback, NULL, &ErrorMsg);

    if (_BackResults[0] == "0") { return true; }

    if( ReturnStatus != SQLITE_OK ){
        cout << "\nSQL error: " << ErrorMsg << endl;
        sqlite3_free(ErrorMsg);
        _BackResults.clear();
        return true;
    } 
    else {
        BackResults = _BackResults;
        _BackResults.clear();
    return false;
    }
} 

//Initialize pointer to zero so that it can be initialized in first call to CreateDatabase
SQLite* SQLite::_Database = 0; 
vector<string> SQLite::_BackResults = {"0"};
