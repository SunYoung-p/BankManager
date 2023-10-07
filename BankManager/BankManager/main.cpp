
#include <iostream>
#include "main.h"

int main()
{	
	BankManager main;
	FileManager file("Todo.txt");
	Customer customer;

	main.SetAcntListCnt(file.LoadData());
	main.SetAcntList(file.GetDataList());

	while(true)
	{
		main.PrintMenu();

		int result = 0;
		result = main.Service(customer.Request());

		if (result == Data::EXIT)
			break;

		cout << "\n\n";
	}

	file.SaveData(main.GetAcntListCnt(), main.GetAcntList());
	

	return 0;
}