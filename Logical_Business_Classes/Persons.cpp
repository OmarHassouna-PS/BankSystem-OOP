#include <iostream>
#include "Persons.h"


Persons::Persons (string Name, string Emile, string Phone) :  
    _Name(Name), _Emile(Emile), _Phone(Phone) {}

void Persons::SettName (string Name)  { _Name = Name;   }
void Persons::SetEmile (string Emile) { _Emile = Emile; }
void Persons::SetPhone (string Phone) { _Phone = Phone; }

string Persons::GetName  () { return _Name ; }
string Persons::GetEmile () { return _Emile ; }
string Persons::GetPhone () { return _Phone ; }
