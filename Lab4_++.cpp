#include <iostream>
#include <windows.h>  
#include "Build.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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
	CPU cpu1 = CPU("Ryzen 5 5600", 3400, 6, 12);
	cout << cpu1++ << endl;
	cout << ++cpu1 << endl;
	CPU cpu2 = cpu1 + 100;
	cout << cpu2 << endl << endl;

	//4. Работа с классом string
	string str = cpu1.GetName();
	cout << str << endl;
	str += " Тест 1"; //конкатенация строк 
	cout << str << endl;
	cout << str.find("5") << endl; //найти первую 5
	str.erase(str.find("5")); //удалить подстроку
	cout << str << endl;
}