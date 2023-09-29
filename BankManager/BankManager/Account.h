#pragma once
#include <iostream>
#include <string>

class Account
{
private:
	int ID;
	char *Name;
	int Money;
	double Rate;

public:

	Account();
	Account(int id, char* name, int money, int Rate);
	~Account();
	int GetID();
	int SetID(int id);
	char* GetName();
	char* SetName(const char* name);
	int GetMoney();
	int SetMoney(int money);
	double GetRate() { return Rate; }
	void SetRate(double rate) { Rate = rate; }
	virtual void MakeAcnt();
	virtual int GetDepositMoney(int);
};