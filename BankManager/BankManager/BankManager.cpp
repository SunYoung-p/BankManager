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
		<< "1. ���� ����" << endl
		<< "2. �� ��" << endl
		<< "3. �� ��" << endl
		<< "4. �������� ��ü ���" << endl
		<< "5. ���α׷� ����" << endl
		<< "����  :  ";
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

	cout << "\n[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;

	Account* acnt = new Account(id, name, money);
	
	AcntList[0] = acnt; // todo. �迭�� ���� ���� account �ֱ�

}