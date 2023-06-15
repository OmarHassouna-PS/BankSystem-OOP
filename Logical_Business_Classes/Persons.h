#pragma once
#include <iostream>

using std::string;

class Persons {

  private:
    string _Name, _Emile, _Phone;

  public:

    Persons (string Name, string Emile, string Phone);

    void SettName (string Name);
    void SetEmile (string Emile);
    void SetPhone (string Phone);

    string GetName  ();
    string GetEmile ();
    string GetPhone ();
};