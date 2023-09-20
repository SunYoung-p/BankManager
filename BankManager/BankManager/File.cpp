#include <iostream>
#include "main.h"

#include <fstream>

int File()
{
	ofstream fout;
	fout.open("song.txt");
	// ios::out | ios::app 를 2번째 인자로 넣어주면, 파일 내용의 맨 끝에 써짐
	// ofstream fout("student.txt", ios::out | ios::app);  와 같이 생성자 활용하여 스트림 생성과 파일 오픈을 동시에 진행 가능
	if (!fout)
		cout << "파일 오픈 실패" << endl;
	else
		cout << "파일이 오픈되었습니다" << endl;

	int age = 210;
	char name[] = "kim";
	fout << age << endl;
	fout << name << endl;

	fout.close();

	return 0;
}