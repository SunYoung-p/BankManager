#include "Account.h"


using namespace std;

Account::Account() : ID(0), Money(0), Name(NULL), Rate(1) {}

Account::Account(int id, char* name, int money, int rate) : ID(id), Money(money), Rate(rate)
{
	int len = strlen(name);
	Name = new char[len + 1];
	strcpy_s(Name, len+1, name);
}

Account::~Account()
{
	//cout << Name << "�� delete �˴ϴ�." << endl;
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
char* Account::SetName(const char* name)
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

void Account::MakeAcnt()
{
	int id, money, rate;
	string name;

	cout << "\n[���� ����\n";
	cout << "ID �Է� : "; cin >> id;
	cout << "�̸� �Է� : "; cin >> name;
	cout << "�ݾ� �Է� : "; cin >> money;
	cout << "������ �Է� : "; cin >> rate;

	this->SetID(id);
	this->SetName(name.c_str());
	this->SetMoney(money);
	this->SetRate(rate);
}

int Account::GetDepositMoney(int money)
{
	return money * (1 + Rate / 100);
}