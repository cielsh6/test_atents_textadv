#include <stdio.h>
#include <string.h>
#include "sString.h"



void sString::Init(const char* text, eStringType type)		//도움함수 1번
{
	_type = type;		//내가 string이라는 구조체에서 꺼내온 type이라는 값을, 이 함수의 type에 넘겨주겠다
	strcpy_s(_text, text);
}


//구조체 포인터 이름 -> 멤버 이름 = (*구조체 포인터 이름)멤버 이름
void sString::Init(const char* text, eStringType type, int selectY, int selectN)
{
	Init(text, type);
	_selectY = selectY;
	_selectN = selectN;
}


void sString::Print()
{
	printf(_text);
	printf("\n");
}

