#include <stdio.h>
#include <conio.h> //_getche()�� �ҷ���
#include <stdlib.h> //atoi(&)�� �ҷ���
#include <string.h> //strcpy �� �ҷ���

#include "sString.h"
#include "sParagraph.h"
#include "sParagraphList.h"



void sParagraphList::Create(int count)
{
	_count = count;
	_list = new sParagraph[_count];
}

void sParagraphList::AddStringToList(int pNo, sString* newString)
{
	_list[pNo].AddString(newString);
}

int sParagraphList::Process(int select)
{

	if (select < _count)
	{
		printf("\n");		//���� ���
		return _list[select].Process();
	}
	return -1;
}

//������
void sParagraphList::Destroy()
{
	delete[] _list;
}

