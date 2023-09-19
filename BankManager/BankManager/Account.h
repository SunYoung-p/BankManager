#pragma once

class Account
{
private:
	int ID;
	char *Name;
	int Money;
public:
	Account();
	Account(int id, char* name, int money);
	~Account();
	int GetID();
	int SetID(int id);
	char* GetName();
	char* SetName(char* name);
	int GetMoney();
	int SetMoney(int money);
};