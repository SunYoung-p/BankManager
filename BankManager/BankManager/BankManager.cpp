#include "BankManager.h"
#include "Account.h"
#include <iostream>

using namespace std;

BankManager::BankManager()
{

}

BankManager::~BankManager()
{
	for (int i = 0; i < data->ACNT_LIST_LEN; i++)
		delete AcntList[i];
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

		case Data::DEPOSIT: break;

		case Data::WITHDRAW: break;

		case Data::INQUIRE: break;

		case Data::EXIT:
		default: break;
	}

	return order;
}


void BankManager::MakeAccnt()
{
	int id, money;
	char* name;
	name = new char[data->NAME_LEN]; 

	cout << "\n[입  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;

	Account* acnt = new Account(id, name, money);
	
	AcntList[0] = acnt; // todo. 배열에 새로 만든 account 넣기

}