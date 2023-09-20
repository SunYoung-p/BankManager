#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account() : ID(0), Money(0), Name(NULL) {}

Account::Account(int id, char* name, int money) : ID(id), Money(money)
{
	int len = strlen(name);
	Name = new char[len + 1];
	strcpy_s(Name, len+1, name);
}

Account::~Account()
{
	//cout << Name << "가 delete 됩니다." << endl;
	delete[] Name;
}

int Account::GetID()
{
	return ID;
}
int Account::SetID(int id)
{
	ID = id;
	
	return ID;
}
char* Account::GetName()
{
	return Name;
}
char* Account::SetName(char* name)
{
	delete[] Name;

	int len = strlen(name);
	Name = new char[len + 1];
	strcpy_s(Name, len + 1, name);

	return Name;
}
int Account::GetMoney()
{
	return Money;
}
int Account::SetMoney(int money)
{
	Money += money;
	
	return Money;
}