#include "Status.h"

string StatusToString(Status status)
{
	string strStatus;

	switch (status)
	{
	case create:
		strStatus = "������";
		break;
	case working:
		strStatus = "� ������";
		break;
	case finished:
		strStatus = "����� � ������";
		break;
	default:
		break;
	}
	return strStatus;
}