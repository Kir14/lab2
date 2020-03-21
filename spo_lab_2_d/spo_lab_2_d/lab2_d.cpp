#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct stud
{
	char fio[20];
	char city[20];
	int ball;
};

stud* show(stud *&, int& );
void write(stud*, char[], char[], char[], char[], int);

int main(int argc, char* argv[])

{
	cout << "start daughter process" << endl;
	cout << "arg" << endl;
	for (int i = 1; i < argc; i++)
	{
		cout << argv[i]<<endl;
	}
	int number = atoi(argv[4]);
	cout << endl;
	int n;
	stud *students= show(students,n);
	write(students, argv[1], argv[2], argv[3], argv[4], n);
	cout << "end daughter process" << endl;
	delete[]students;
	system("pause");
	return 0;
}

stud* show(stud *&students, int& n)
{
	LPCTSTR fn = "G:\\Files\\File_1.txt";
	HANDLE myFile = CreateFile(
		fn,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error";
	else
		cout << " File is opened" << endl;
	n = GetFileSize(myFile, NULL)/sizeof(stud);
	students=new stud[n];
	int i = 0;
	stud student;
	DWORD m;
	while (ReadFile(myFile, &student, sizeof(stud), &m, NULL) && m != 0)
	{
		strcpy_s(students[i].fio, student.fio);
		strcpy_s(students[i].city, student.city);
		students[i].ball = student.ball;
		i++;
	}
	/*for (i = 0; i < n; i++)
	{
		cout << setw(10) << students[i].fio << setw(10) << students[i].city << setw(7) << students[i].ball << endl;
	}*/
	CloseHandle(myFile);

	return students;
}


void write(stud* students, char fio[], char city[], char bal[], char nStud[], int n)
{
	int number = atoi(nStud);
	int ball = atoi(bal);

	if (number > n)
	{
		cout << "Error" << endl;
		return;
	}
	
	LPCTSTR fn = "G:\\Files\\File_1.txt";
	HANDLE myFile = CreateFile(
		fn, 
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error";
	else
		cout << " File was changed" << endl;
	strcpy_s(students[number-1].fio, fio);
	strcpy_s(students[number-1].city, city);
	students[number-1].ball = ball;
	DWORD m;
	for (int i = 0; i < n; i++)
	{
		WriteFile(myFile, &students[i], sizeof(stud), &m, NULL);
	}
	CloseHandle(myFile);



	return;
}