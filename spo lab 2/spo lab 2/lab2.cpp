#include <windows.h>
#include <iostream> 
#include <iomanip>
using namespace std; 

struct stud
{
	char fio[20];
	char city[20];
	int ball;
};


void show();

int main() {

	show();
	
	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);


	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));

	char nStruct[20];
	char fio[20], city[20],ball[20];
	cout << "number of structure: ";
	cin >> nStruct;
	cout << "Enter new Fio: ";
	cin >> fio;
	cout << "Enter new city: ";
	cin >> city;
	cout << "Enter new ball: ";
	cin >> ball;

	char daughter[] = "G:\\spo 2 lab\\spo_lab_2_d\\Debug\\spo_lab_2_d.exe";
	char name[100]= "G:\\spo 2 lab\\spo_lab_2_d\\Debug\\spo_lab_2_d.exe"; strcat_s(name, " ");
	strcat_s(name, fio); strcat_s(name, " ");
	strcat_s(name, city); strcat_s(name, " ");
	strcat_s(name, ball); strcat_s(name, " ");
	strcat_s(name, nStruct); strcat_s(name, " ");
	if (!CreateProcess(daughter,name , NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcInfo))   return 0;


	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);

	show();

	return 0;
}


void show()
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

	stud student;
	DWORD m;
	while (ReadFile(myFile, &student, sizeof(stud), &m, NULL) && m != 0)
	{
		cout << setw(10) << student.fio << setw(10) << student.city << setw(7) << student.ball << endl;
	}
	CloseHandle(myFile);
	system("pause");
	return;
}
