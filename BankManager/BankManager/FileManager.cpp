#include "FileManager.h"

FileManager::FileManager(string name) : FileName(name)
{
	
}

FileManager::~FileManager()
{

}

int FileManager::LoadData()
{
	File.open(FileName, ios::in | ios::out);

	if (File.is_open() == false)
	{
		cerr << "파일 오픈 실패 ! " << endl;

		return -1;
	}

	int cnt=0;

	File >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int id;
		string name;
		int money;
		int rate;
		int level;
		bool IsCredit;

		File >> IsCredit;

		if (IsCredit)
		{
			File >> id;
			File >> name;
			File >> money;
			File >> rate;
			File >> level;

			CreditAccount* acnt = new CreditAccount(IsCredit, id, name.c_str(), money, rate, level);
			LoadList[i] = acnt;
		}
		else
		{
			File >> id;
			File >> name;
			File >> money;
			File >> rate;

			Account* acnt = new Account(IsCredit, id, name.c_str(), money, rate);
			LoadList[i] = acnt;
		}
	}


	File.close();

	return cnt;
	// cout << cnt << "," << val.GetID() << ", " << val.GetName() << ", "
	// 	<< val.GetMoney() << endl;
}

void FileManager::SaveData(int cnt, Account** Accnt)
{
	File.open(FileName, ios::out);

	if (File.is_open() == false)
	{
		cerr << "파일 저장 실패 ! " << endl;

		return;
	}

	File << cnt << endl;
	
	for (int i = 0; i < cnt; i++)
	{
		File << Accnt[i]->GetIsCredit() << endl;
		File << Accnt[i]->GetID() << endl;
		string name(Accnt[i]->GetName());
		File << name << endl;
		File << Accnt[i]->GetMoney() << endl;
		File << Accnt[i]->GetRate() << endl;

		if (Accnt[i]->GetIsCredit())
			File << static_cast<CreditAccount*>(Accnt[i])->GetLevel() << endl;
	}

	File.close();
}