#include "BankManager.h"
#include "Account.h"
#include <iostream>

using namespace std;

BankManager::BankManager() : AcntListCnt(0), AcntListLen(10)
{
	for (int i = 0; i < AcntListLen; i++)
		AcntList[i] = NULL;
}

BankManager::~BankManager()
{
	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] != NULL)
		{
			//cout << "AcntList[" << i << "] Delete 시도" << endl;
			
			delete AcntList[i];
		}
	}
}

void BankManager::PrintMenu()
{
	cout << "------------ Menu ------------" << endl
		<< "1. 계좌 개설" << endl
		<< "2. 입 금" << endl
		<< "3. 출 금" << endl
		<< "4. 계좌정보 전체 출력" << endl
		<< "5. 프로그램 종료" << endl
		<< "선택  :  ";
}

int BankManager::Service(int order)
{
	switch (order)
	{
	case Data::MAKE: MakeAccnt();  break;

	case Data::DEPOSIT: Deposit();  break;

	case Data::WITHDRAW: Withdraw(); break;

		case Data::INQUIRE: Inquire();  break;

		case Data::EXIT:
		default: break;
	}

	return order;
}


void BankManager::MakeAccnt()
{
	int sel;

	cout << endl << "[계좌 종류 선택]" << endl;
	cout << "(1) 일반 계좌" << endl;
	cout << "(2) 신용 등급 계좌" << endl;
	cout << "선택 [1, 2]  :  ";

	cin >> sel;

	if (sel == 1)
	{
		Account* acnt = new Account();
		acnt->MakeAcnt();

		AcntList[AcntListCnt] = acnt;
		AcntListCnt++;
	}
	else if (sel == 2)
	{
		CreditAccount* acnt = new CreditAccount();
		acnt->MakeAcnt();

		AcntList[AcntListCnt] = acnt;
		AcntListCnt++;
	}
}

void BankManager::Inquire()
{

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;

		cout << "\n이 름 : " << AcntList[i]->GetName() << endl;
		cout << "금 액 : " << AcntList[i]->GetMoney() << endl;
	}
}

int BankManager::Deposit()
{
	int id, money;

	cout << "\n입금 ID 입력 : ";
	cin >> id;
	cout << "입 금 액 : ";
	cin >> money;

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;
		
		if (AcntList[i]->GetID() == id)
		{
			AcntList[i]->SetMoney(AcntList[i]->GetDepositMoney(money));
			cout << money << " 입금하여 총 " << AcntList[i]->GetMoney() << "원 입니다." << endl;

			return AcntList[i]->GetMoney();
		}
	}

	cout << "입금 실패, ID 확인하세요" << endl;

	return -1;
}

int BankManager::Withdraw()
{
	int id, money;

	cout << "\n출금 ID 입력 : ";
	cin >> id;
	cout << "출 금 액 : ";
	cin >> money;

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;
		
		if (AcntList[i]->GetID() == id  &&  money >=0)
		{
			AcntList[i]->SetMoney(money * -1);
			cout << money << " 출금하여 총 " << AcntList[i]->GetMoney() << "원 입니다." << endl;

			return AcntList[i]->GetMoney();
		}
	}

	cout << "출금 실패, ID 확인하세요" << endl;

	return -1;
}


int BankManager::SetAcntList(Account** val)
{
	for (int i = 0; i < AcntListCnt; i++)
	{
		AcntList[i] = val[i];
	}

	return AcntListCnt;
}