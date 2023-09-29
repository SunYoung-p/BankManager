#include "CreditAccount.h"

void CreditAccount::MakeAcnt()
{
	int id, money, rate, level;
	string name;

	cout << "\n[���� ����\n";
	cout << "ID �Է� : "; cin >> id;
	cout << "�̸� �Է� : "; cin >> name;
	cout << "�ݾ� �Է� : "; cin >> money;
	cout << "������ �Է� : "; cin >> rate;
	cout << "�ſ��� �Է� (A:1, B:2, C:3, D:4) :  "; cin >> level;

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

