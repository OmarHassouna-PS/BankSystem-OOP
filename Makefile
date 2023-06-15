Bank: Persons.o SQLite.o Clients.o Validation.o HeaderScreen.o MainScreen.o TransactionsScreen.o 
	@echo "Linking files to gather"
	g++ Bank.cpp -o Bank Persons.o SQLite.o Clients.o Validation.o HeaderScreen.o MainScreen.o TransactionsScreen.o sqlite3.dll

Clients.o: Logical_Business_Classes/Clients.cpp Logical_Business_Classes/Clients.h
	g++ -c Logical_Business_Classes/Clients.cpp 
	
SQLite.o: Logical_Business_Classes/SQLite.cpp Logical_Business_Classes/SQLite.h
	g++ -c Logical_Business_Classes/SQLite.cpp

Persons.o: Logical_Business_Classes/Persons.cpp Logical_Business_Classes/Persons.h
	g++ -c Logical_Business_Classes/Persons.cpp

HeaderScreen.o: User_Interface_Classes/HeaderScreen.cpp User_Interface_Classes/HeaderScreen.h
	g++ -c User_Interface_Classes/HeaderScreen.cpp
	
MainScreen.o: User_Interface_Classes/MainScreen.cpp User_Interface_Classes/MainScreen.h
	g++ -c User_Interface_Classes/MainScreen.cpp

TransactionsScreen.o: User_Interface_Classes/TransactionsScreen.cpp User_Interface_Classes/TransactionsScreen.h
	g++ -c User_Interface_Classes/TransactionsScreen.cpp

Validation.o: Logical_Business_Classes/Validation.cpp Logical_Business_Classes/Validation.h
	g++ -c Logical_Business_Classes/Validation.cpp

clean:
	@echo "Clean Files"
	del *.o Bank.exe





	