#include "Build.h"

inline void clean()  //Î÷èñòêà ïîòîêà
{
	while (getchar() != '\n');
}

Build::Build()
{
	number = 0;
	pc = PC();
	status = create;
}

Build::Build(int number)
{
	this->number = number;
	pc = PC();
	status = create;
}

Build::Build(int number, PC pc, string client, Status status)
{
	if (CheckCor(number, pc, client, status))
	{
		this->number = number;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}

Build::~Build()
{
}

bool Build::CheckCor(int number, PC pc, string client, Status status)
{
	if (number > 0 && size(client) != 0 && (status >= create && status <= finished))
		return true;
	else
	{
		printf("Íåâåğíî, âûõîä èç ïğîãğàììû...");
		exit(-1);
	}
}

int Build::GetNum()
{
	return number;
}

PC Build::GetPC()
{
	return pc;
}

string Build::GetClient()
{
	return client;
}

Status Build::GetStatus()
{
	return status;
}

void Build::input_build()
{
	int number;
	string client;
	printf("Ââîä äàííûõ çàêàçà\n\n");
	do
	{
		printf("Ââåäèòå íîìåğ çàêàçà: ");
		scanf("%d", &number);
		clean();
	} while (number <= 0);
	printf("Ââåäèòå èìÿ êëèåíòà: ");
	getline(cin, client);
	Status status;
	do
	{
		printf("Ââåäèòå ñòàòóñ çàêàçà, ãäå\n0 - Çàêàç ñîçäàí\n1 - Çàêàç â ğàáîòå\n2 - Çàêàç âûïîëíåí\nÂàø âûáîğ: ");
		scanf("%d", &status);
		clean();
	} while (status < 0 && status > 2);
	pc.input_pc();
	SetBuild(number, pc, client, status);
}

void Build::out_build()
{
	printf("\nÈíôîğìàöèÿ î çàêàçå:\n\n");
	printf("Íîìåğ çàêàçà: %d\n", GetNum());
	printf("Êëèåíò - %s\n", GetClient().c_str());
	printf("Ñòàòóñ - %s\n", StatusToString(GetStatus()).c_str());
	pc.Out_PC();
}

void Build::ChangeStatus(Status newstatus)
{
	if (newstatus >= create && newstatus <= finished) {
		this->status = newstatus;
		printf("Ñîñòîÿíèå çàêàçà óñïåøíî èçìåíåíî!\n");
	}
	else {
		printf("Íåâåğíî, âûõîä èç ïğîãğàììû...");
		exit(-1);
	}
}

void Build::SetPC(PC pc)
{
	this->pc = pc;
}

void Build::SetBuild(int number, PC pc, string client, Status status)
{
	if (CheckCor(number, pc, client, status))
	{
		this->number = number;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}