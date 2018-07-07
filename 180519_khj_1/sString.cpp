#include <stdio.h>
#include <string.h>
#include "sString.h"


sString::sString()	// ������ (sStringŬ������ �����ɶ� �ݵ�� �����Ǵ°�, ��ü�� ��)
{
	_prev = NULL;
	_next = NULL;
}

sString::sString(const char* text, eStringType type, int selectY, int selectN)	//�ι�° ������, ��ȣ���� ���ڸ� ���� ��� �̰� ���� ��Ŵ
{
	_prev = NULL;
	_next = NULL;
	Init(text, type, selectY, selectN);
}

sString::~sString()	// ������
{

}


void sString::Init(const char* text, eStringType type)
{
	_type = type;		//���� string�̶�� ����ü���� ������ type�̶�� ����, �� �Լ��� type�� �Ѱ��ְڴ�
	strcpy_s(_text, text);
}


//����ü ������ �̸� -> ��� �̸� = (*����ü ������ �̸�)��� �̸�
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

