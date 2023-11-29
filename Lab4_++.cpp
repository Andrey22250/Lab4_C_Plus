#include <iostream>
#include <windows.h>  
#include "Build.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом "Build"
	//1. Пример работы со статическим методом
	for (int i = 0; i < 5; i++)
	{
		Build ex = Build();
		printf("Номер заказа: %d\n", ex.GetNumBuild());
	}

	//2. Возврат значения через указатель и ссылку
	PC ex1 = PC();
	Motherboard* mrbrd = ex1.GetMrbrd();
	CPU& cpu = ex1.GetCpu();
	cout << "Название МП: " << mrbrd->GetName() << std::endl;
	cout << "Название ЦПУ: " << cpu.GetName() << std::endl;

	//3. Перегрузка оператора +,++
	RAM ram = RAM();
	std::cout << ram++ << std::endl;
	std::cout << ++ram << std::endl;
	RAM ram2 = ram + 100;
	std::cout << ram2 << std::endl << std::endl;
}