#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
#include "CreditAccount.h"

using namespace std;

class FileManager
{
private:
	fstream File;
	string FileName;
	Account *LoadList[10];
public:
	FileManager(string);
	~FileManager();
	int LoadData();
	void SaveData(int, Account**);
	Account** GetDataList() { return LoadList; }
};