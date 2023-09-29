#pragma once
#include "Data.h"
#include "Account.h"
#include "CreditAccount.h"

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
	void SetAcntListCnt(int n) { AcntListCnt = n; }
	int GetAcntListCnt() { return AcntListCnt; }
	Account** GetAcntList() { return AcntList; }
	int SetAcntList(Account**);
};