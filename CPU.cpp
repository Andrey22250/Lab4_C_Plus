#include <iostream>
#include <string>
#include "CPU.h"

inline void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

bool CPU::CheckCor(string name_cpu, int frequency, int cores, int treads)
{
	if (size(name_cpu) != 0 && frequency > 0 && cores > 0 && treads > 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

void CPU::SetCpu(string name_cpu, int frequency, int cores, int treads)
{
	if (CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}
//Конструкторы
CPU::CPU()
{
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu)
{
	this->name_cpu = name_cpu;
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu, int frequency, int cores, int treads)
{
	if (CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}
//Деструктор
CPU::~CPU()
{
}

//Получение
int CPU::GetFrequency()
{
	return frequency;
}

int CPU::GetCores()
{
	return cores;
}

int CPU::GetTreads()
{
	return treads;
}

string CPU::GetName()
{
	return name_cpu;
}
//Ввод
void CPU::input_cpu()
{
	int frequency, cores, treads;
	string name_cpu;
	printf("\nВвод параметров процессора\n");
	printf("\nВведите название процессора: ");
	getline(cin, name_cpu);
	do
	{
		printf("Введите частоту процессора в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 7000);
	do
	{
		printf("Введите кол-во ядер: ");
		scanf("%d", &cores);
		clean();
	} while (cores <= 0 || cores > 256);
	do
	{
		printf("Введите кол-во потоков: ");
		scanf("%d", &treads);
		clean();
	} while (treads <= 0 && treads > 512);
	SetCpu(name_cpu, frequency, cores, treads);
}