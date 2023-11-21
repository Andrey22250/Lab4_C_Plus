#pragma once
#include <iostream>
#include <string>
#include "PC.h"
#include "Status.h"

class Build
{
public:
	Build();
	Build(int number);
	Build(int number, PC pc, string client, Status status);
	~Build();

	bool CheckCor(int number, PC pc, string client, Status status);

	int GetNum();
	PC GetPC();
	string GetClient();
	Status GetStatus();
	void input_build();
	void out_build();
	void ChangeStatus(Status newstatus);
	void SetPC(PC pc);
	void SetBuild(int number, PC pc, string client, Status status);
private:
	int number;
	PC pc;
	string client;
	Status status;
};
