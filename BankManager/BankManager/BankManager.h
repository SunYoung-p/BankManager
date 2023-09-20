#pragma once
#include "Data.h"
#include "Account.h"

class BankManager
{
private:
	Data* data;
	Account* AcntList[10];
	int AcntListCnt;
	int AcntListLen;
public:
	BankManager();
	~BankManager();
	void PrintMenu();
	int Service(int);
	void MakeAccnt();
	void Inquire();
	int Deposit();
	int Withdraw();
};