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
			//cout << "AcntList[" << i << "] Delete �õ�" << endl;
			
			delete AcntList[i];
		}
	}
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
	int id, money;
	char name[20];

	cout << "\n[��  ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;

	Account* acnt = new Account(id, name, money);
	
	AcntList[AcntListCnt] = acnt; 
	AcntListCnt++;

}

void BankManager::Inquire()
{

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;

		cout << "\n�� �� : " << AcntList[i]->GetName() << endl;
		cout << "�� �� : " << AcntList[i]->GetMoney() << endl;
	}
}

int BankManager::Deposit()
{
	int id, money;

	cout << "\n�Ա� ID �Է� : ";
	cin >> id;
	cout << "�� �� �� : ";
	cin >> money;

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;
		
		if (AcntList[i]->GetID() == id)
		{
			AcntList[i]->SetMoney(money);
			cout << money << " �Ա��Ͽ� �� " << AcntList[i]->GetMoney() << "�� �Դϴ�." << endl;

			return AcntList[i]->GetMoney();
		}
	}

	cout << "�Ա� ����, ID Ȯ���ϼ���" << endl;

	return -1;
}

int BankManager::Withdraw()
{
	int id, money;

	cout << "\n��� ID �Է� : ";
	cin >> id;
	cout << "�� �� �� : ";
	cin >> money;

	for (int i = 0; i < AcntListLen; i++)
	{
		if (AcntList[i] == NULL)
			break;
		//
		if (AcntList[i]->GetID() == id  &&  money >=0)
		{
			AcntList[i]->SetMoney(money * -1);
			cout << money << " ����Ͽ� �� " << AcntList[i]->GetMoney() << "�� �Դϴ�." << endl;

			return AcntList[i]->GetMoney();
		}
	}

	cout << "��� ����, ID Ȯ���ϼ���" << endl;

	return -1;
}