#pragma once
#include "Account.h"
#include <iostream>

using namespace std;

class CreditAccount : public Account
{
private:
	int Level;

public:
	CreditAccount() : Account() {}
	CreditAccount(int id, char* name, int money, int rate, int level)
		: Account(id, name, money, rate), Level(level)
	{

	}

	int GetLevel() { return Level; }
	void SetLevel(int level) { Level = level; }
	void MakeAcnt() override;
	int GetDepositMoney(int ) override;
};