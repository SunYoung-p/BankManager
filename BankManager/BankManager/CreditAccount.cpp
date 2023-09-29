#include "CreditAccount.h"

void CreditAccount::MakeAcnt()
{
	int id, money, rate, level;
	string name;

	cout << "\n[계좌 개설\n";
	cout << "ID 입력 : "; cin >> id;
	cout << "이름 입력 : "; cin >> name;
	cout << "금액 입력 : "; cin >> money;
	cout << "이자율 입력 : "; cin >> rate;
	cout << "신용등급 입력 (A:1, B:2, C:3, D:4) :  "; cin >> level;

	this->SetID(id);
	this->SetName(name.c_str());
	this->SetMoney(money);
	this->SetRate(rate);
	this->SetLevel(level);
}

int CreditAccount::GetDepositMoney(int money)
{
	double ExceptRate;
	int DepositMoney;

	switch (Level)
	{
		case 1: ExceptRate = 10; break;
		case 2: ExceptRate = 7.5; break;
		case 3: ExceptRate = 5; break;
		case 4: ExceptRate = 3; break;
		default:
			break;
	}

	DepositMoney = money * (
		1 
		+ ExceptRate / 100 
		+ this->GetRate() / 100
		);

	return DepositMoney;
}

