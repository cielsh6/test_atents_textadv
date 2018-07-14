#include <stdio.h>
#include <conio.h> //_getche()¸¦ ºÒ·¯¿È
#include <stdlib.h> //atoi(&)¸¦ ºÒ·¯¿È
#include <string.h> //strcpy ¸¦ ºÒ·¯¿È

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
		printf("\n");		//ÇÑÁÙ ¶ç°í
		return _list[select].Process();
	}
	return -1;
}

//¼÷Á¦¿ë
void sParagraphList::Destroy()
{
	delete[] _list;
}

