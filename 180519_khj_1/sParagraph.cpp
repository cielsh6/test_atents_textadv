#include <stdio.h>
#include <conio.h>

#include "sString.h"
#include "sParagraph.h"




sParagraph::sParagraph()
{
	_current = NULL;
}

sParagraph::~sParagraph()		//�޸� ��ƴ� ������ ������
{
	_current = _start;
	while (NULL != _current)
	{
		sString* nextString = _current->GetNext();
		delete _current;
		_current = nextString;
	}
}


void sParagraph::AddString(sString* string)		//�����Լ� 2��
{

	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���
	if (NULL == _current)
	{
		//ù ����
		_current = string;	//���� ���� ����
		string->InitNode(NULL, NULL);
		_start = string;
	}
	else
	{
		//ù ���� �ƴ�
		_current->SetNext(string);
		string->InitNode(_current, NULL);
		_current = string;
	}
}


int sParagraph::Process()
{
	int nextSelect = 0;
	_current = _start;		//���� ����� ������ ���� �������� ���� = ���� ������� ����ϰڴ�

	while (NULL != _current)
	{

		/*
		switch (_current->GetType())
		{
		case TEXT:
			nextSelect = _current->Process();
			break;
		case BRANCH:
			nextSelect = _current->Process();
			break;
		case QUIT:
			nextSelect = _current->Process();
		}
		*/
		nextSelect = _current->Process();
		_current = _current->GetNext();

	}

	//return 0;
	return nextSelect;
}
