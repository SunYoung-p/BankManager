#include <iostream>
#include "main.h"

#include <fstream>

int File()
{
	ofstream fout;
	fout.open("song.txt");
	// ios::out | ios::app �� 2��° ���ڷ� �־��ָ�, ���� ������ �� ���� ����
	// ofstream fout("student.txt", ios::out | ios::app);  �� ���� ������ Ȱ���Ͽ� ��Ʈ�� ������ ���� ������ ���ÿ� ���� ����
	if (!fout)
		cout << "���� ���� ����" << endl;
	else
		cout << "������ ���µǾ����ϴ�" << endl;

	int age = 210;
	char name[] = "kim";
	fout << age << endl;
	fout << name << endl;

	fout.close();

	return 0;
}