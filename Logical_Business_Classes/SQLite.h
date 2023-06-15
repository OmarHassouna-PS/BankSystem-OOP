#pragma once
#include <iostream>
#include <vector>
#include "../sqlite/sqlite3.h"
using std::endl;using std::cout;using std::string;using std::cout;using std::vector;

class SQLite
{
   private:
      static SQLite* _Database;
      static vector<string> _BackResults;
      const char* _GlobalPath;
      sqlite3* db;
      
   // Private constructor so that no objects can be created.
   SQLite();
   ~SQLite ();

   static int callback(void *data, int argc, char **argv, char **azColName);

   public:

      // Create or return a pointer to this object designed with the Singleton pattern
      static SQLite* CreateDatabase();

      void SetPathDatabaseFile (const char* FileName);

      bool OpenDatabase ();

      void CloseDatabase ();

      void DeletePointerDatabase ();

      // Send Only 
      bool ExecuteQuery (string SQLQuery);
      
      // Back Only One Record
      bool ExecuteQuery (string SQLQuery, vector<string>& BackResults);   
};
