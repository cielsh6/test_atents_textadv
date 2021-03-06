#include <stdio.h>
#include <conio.h>

#include "sString.h"
#include "sParagraph.h"




sParagraph::sParagraph()
{
	_current = NULL;
}

sParagraph::~sParagraph()		//메모리 잡아다 썼으면 지워라
{
	_current = _start;
	while (NULL != _current)
	{
		sString* nextString = _current->GetNext();
		delete _current;
		_current = nextString;
	}
}


void sParagraph::AddString(sString* string)		//도움함수 2번
{

	// 첫 문장일 때, 첫 문장이 아닐 때 세팅이 다르다
	if (NULL == _current)
	{
		//첫 문장
		_current = string;	//현재 문장 세팅
		string->InitNode(NULL, NULL);
		_start = string;
	}
	else
	{
		//첫 문장 아님
		_current->SetNext(string);
		string->InitNode(_current, NULL);
		_current = string;
	}
}


int sParagraph::Process()
{
	int nextSelect = 0;
	_current = _start;		//현재 출력할 문장을 시작 문장으로 세팅 = 시작 문장부터 출력하겠다

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
