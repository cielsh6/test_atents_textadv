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

	// �̰� �׳� ���� �߰��Ѱ�
	printf("�ٽ� �����ұ�? Y or N");
	char ch = _getche();
	if ('n' == ch || 'N' == ch)
	{
		return -1;
	}

	return 0;
}