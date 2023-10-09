#include <iostream>

using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void PrintArr(const T* p, int size)
{
	for (int i = 0; i < size; i++)
		cout << i + 1 << "��° �� : " << p[i] << endl;

	cout << endl;
}

int Template()
{
	int a1 = 5, b1 = 10;
	double a2 = 1.5, b2 = 2.5;
	cout << a1 << ", " << b1 << " �� swap ��Ű�� : ";
	Swap(a1, b1);
	cout << a1 << ", " << b1 << endl;

	cout << a2 << ", " << b2 << " �� swap ��Ű�� : ";
	Swap(a2, b2);
	cout << a2 << ", " << b2 << endl;


	int intArr[5] = { 1,2,3,4,5 };
	double doubleArr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	char charArr[5] = { 'a', 'b', 'c', 'd', 'e'};

	PrintArr(intArr, sizeof(intArr) / sizeof(int));
	PrintArr(doubleArr, sizeof(doubleArr) / sizeof(double));
	PrintArr(charArr, sizeof(charArr) / sizeof(char));

	return 0;
}