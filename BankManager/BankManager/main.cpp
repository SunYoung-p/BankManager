#include <iostream>
#include "main.h"

int main()
{
	BankManager main;
	Customer customer;

	while(true)
	{
		main.PrintMenu();

		int result = 0;
		result = main.Service(customer.Request());

		if (result == Data::EXIT)
			break;

		cout << "\n\n";
	}

	return 0;
}