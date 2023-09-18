#pragma once
#include "Data.h"
#include "Account.h"

class BankManager
{
private:
	Data* data;
	Account* AcntList[10];
	
public:
	BankManager();
	~BankManager();
	void PrintMenu();
	int Service(int);
	void MakeAccnt();

};