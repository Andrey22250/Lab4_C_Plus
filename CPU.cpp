#include <iostream>
#include <string>
#include "CPU.h"

inline void clean()  //������� ������
{
	while (getchar() != '\n');
}

bool CPU::CheckCor(string name_cpu, int frequency, int cores, int treads)
{
	if (size(name_cpu) != 0 && frequency > 0 && cores > 0 && treads > 0)
		return true;
	else
	{
		printf("�������, ����� �� ���������...");
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
//������������
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
//����������
CPU::~CPU()
{
}

//���������
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
//����
void CPU::input_cpu()
{
	int frequency, cores, treads;
	string name_cpu;
	printf("\n���� ���������� ����������\n");
	printf("\n������� �������� ����������: ");
	getline(cin, name_cpu);
	do
	{
		printf("������� ������� ���������� � ���: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 7000);
	do
	{
		printf("������� ���-�� ����: ");
		scanf("%d", &cores);
		clean();
	} while (cores <= 0 || cores > 256);
	do
	{
		printf("������� ���-�� �������: ");
		scanf("%d", &treads);
		clean();
	} while (treads <= 0 && treads > 512);
	SetCpu(name_cpu, frequency, cores, treads);
}