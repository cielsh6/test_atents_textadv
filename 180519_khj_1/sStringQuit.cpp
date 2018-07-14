#include <conio.h>
#include <stdio.h>

#include "sStringQuit.h"


sStringQuit::sStringQuit()
{

}
sStringQuit::~sStringQuit()
{

}

int sStringQuit::Process()
{
	Print();

	// 이건 그냥 내가 추가한거
	printf("다시 시작할까? Y or N");
	char ch = _getche();
	if ('n' == ch || 'N' == ch)
	{
		return -1;
	}

	return 0;
}