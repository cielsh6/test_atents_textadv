#include <stdio.h>
#include <string.h>
#include "sString.h"


sString::sString()	// 생성자 (sString클래스가 생성될때 반드시 생성되는거, 객체가 함)
{
	_prev = NULL;
	_next = NULL;
}

sString::sString(const char* text, eStringType type, int selectY, int selectN)	//두번째 생성자, 괄호안의 인자를 받을 경우 이걸 생성 시킴
{
	_prev = NULL;
	_next = NULL;
	Init(text, type, selectY, selectN);
}

sString::~sString()	// 해제자
{

}


void sString::Init(const char* text, eStringType type)
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

