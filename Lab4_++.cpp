#include <iostream>
#include <windows.h>  
#include "Build.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом "Build"
	Build* BuildArr = new Build[2];
	for (int i = 0; i < 2; i++)
	{
		BuildArr[i].out_build();
	}
	BuildArr[0].ChangeStatus(finished);
	BuildArr[0].out_build();
	delete[] BuildArr;
}