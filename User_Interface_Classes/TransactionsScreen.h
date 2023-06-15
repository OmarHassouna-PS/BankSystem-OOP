#pragma once
#include <iostream>
#include <vector>
#include "MainScreen.h"


class TransactionsScreen : protected MainScreen {

private:
    static void _ShowTransactionsMenu();

public:
    static void Transactions ();
};
