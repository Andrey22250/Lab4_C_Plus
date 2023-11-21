#include "Ram.h"

inline void clean()  //������� ������
{
	while (getchar() != '\n');
}

RAM::RAM()
{
	frequency = mem = 0;
}

RAM::RAM(string type_ddr)
{
	this->type_ddr = type_ddr;
	frequency = mem = 0;
}

RAM::RAM(string type_ddr, int frequency, int mem)
{
	if (CheckCor(type_ddr, frequency, mem))
	{
		this->type_ddr = type_ddr;
		this->frequency = frequency;
		this->mem = mem;
	}
}

RAM::~RAM()
{
}

bool RAM::CheckCor(string type_ddr, int frequency, int mem)
{
	if (size(type_ddr) != 0 && frequency > 0 && mem > 0)
		return true;
	else
	{
		printf("�������, ����� �� ���������...");
		exit(-1);
	}
}

string RAM::GetType()
{
	return type_ddr;
}

int RAM::GetFrequencyRam()
{
	return frequency;
}

int RAM::GetMem()
{
	return mem;
}

void RAM::input_ram()
{
	printf("\n���� ���������� ���\n");
	string type_ddr;
	int frequency, mem;
	printf("\n������� ��� ���: ");
	getline(cin, type_ddr);
	do
	{
		printf("������� ������� ��� � ���: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 12000);
	do
	{
		printf("������� ����� ���: ");
		scanf("%d", &mem);
		clean();
	} while (mem <= 0);
	SetRam(type_ddr, frequency, mem);
}

void RAM::SetRam(string type_ddr, int frequency, int mem)
{
	if (CheckCor(type_ddr, frequency, mem))
	{
		this->type_ddr = type_ddr;
		this->frequency = frequency;
		this->mem = mem;
	}
}