#include "PC.h"

inline void clean()  //������� ������
{
	while (getchar() != '\n');
}

PC::PC()
{
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	mrbrd = Motherboard();
	price = 0;
}

PC::PC(float price)
{
	if (price > 0)
	{
		cpu = CPU();
		gpu = GPU();
		ram = RAM();
		mrbrd = Motherboard();
		this->price = price;
	}
}

PC::PC(float price, CPU cpu, GPU gpu, RAM ram, Motherboard mrbrd)
{
	if (price > 0)
	{
		this->price = price;
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		this->mrbrd = mrbrd;
	}
}

PC::~PC()
{
}

float PC::GetPrice()
{
	return price;
}

CPU PC::GetCpu()
{
	return cpu;
}

GPU PC::GetGpu()
{
	return gpu;
}

RAM PC::GetRam()
{
	return ram;
}

Motherboard PC::GetMrbrd()
{
	return mrbrd;
}

void PC::input_pc()
{
	float price;
	printf("\n���� ���������� � ����������\n");
	do
	{
		printf("������� ���� ��: ");
		scanf("%f", &price);
		clean();
	} while (price <= 0);
	cpu.input_cpu();
	gpu.input_gpu();
	ram.input_ram();
	mrbrd.input_mrbrd();
	SetPrice(price);
}

void PC::Undervolt_GPU()
{
	if (this->gpu.GetTDP() - 3 > this->gpu.GetMin_TDP())
	{
		gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetTDP() - 3);
		if (this->gpu.GetTDP() <= this->gpu.GetMin_TDP())
			gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetMin_TDP());
	}
	else printf("Undervolt ����������!");
}

void PC::Out_PC()
{
	printf("\n���������� � ������:\n\n");
	printf("���������: %s, %d ���, %d ����, %d �������\n", this->cpu.GetName().c_str(), this->cpu.GetFrequency(), this->cpu.GetCores(), this->cpu.GetTreads());
	printf("����������: %s, %d VRAM, %d TDP\n", this->gpu.GetName().c_str(), this->gpu.GetVram(), this->gpu.GetTDP());
	printf("���: %s, %d �������, %d �����\n", this->ram.GetType().c_str(), this->ram.GetFrequencyRam(), this->ram.GetMem());
	printf("����������� �����: %s, %s ������\n", this->mrbrd.GetName().c_str(), this->mrbrd.GetChipset().c_str());
	printf("���� ������: %.2f\n\n", this->price);
}

void PC::SetPrice(float price)
{
	this->price = price;
}