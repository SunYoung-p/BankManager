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
		Account* val = new Account();	
		int id;
		string name;
		int money;
		int rate;

		File >> id;
		File >> name;
		File >> money;
		File >> rate;

		val->SetID(id);
		val->SetName(name.c_str());
		val->SetMoney(money);
		val->SetRate(rate);

		LoadList[i] = new Account();
		LoadList[i] = val;
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
		File << Accnt[i]->GetID() << endl;
		string name(Accnt[i]->GetName());
		File << name << endl;
		File << Accnt[i]->GetMoney() << endl;
		File << Accnt[i]->GetRate() << endl; // todo, Virtual로 Account와 CreditAccount에 data save 추가하기
	}

	File.close();
}