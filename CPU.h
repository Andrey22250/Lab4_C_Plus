#pragma once
#include <iostream>
#include <string>

using namespace std;

class CPU
{
public:
	CPU();
	CPU(string name_cpu);
	CPU(string name_cpu, int frequency, int cores, int treads);
	~CPU();

	bool CheckCor(string name_cpu, int frequency, int cores, int treads);

	string GetName();
	int GetFrequency();
	int GetCores();
	int GetTreads();
	void input_cpu();
	void SetCpu(string name_cpu, int frequency, int cores, int treads);
private:
	string name_cpu;
	int frequency;
	int cores, treads;
};