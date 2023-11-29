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
	cout << "Название МП: " << mrbrd->GetName() << endl;
	cout << "Название ЦПУ: " << cpu.GetName() << endl;

	//3. Перегрузка оператора +,++
	CPU cpu = CPU();
	cout << cpu++ << endl;
	cout << ++cpu << endl;
	CPU cpu2 = cpu + 100;
	cout << cpu2 << endl << endl;
}