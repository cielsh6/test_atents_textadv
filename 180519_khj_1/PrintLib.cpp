#include <stdio.h>
#include <conio.h> //_getche()를 불러옴
#include <stdlib.h> //atoi(&)를 불러옴
#include <string.h> //strcpy 를 불러옴
#include "sString.h"
#include "PrintLib.h"


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


int sParagraph::Print()
{
	
	_current = _start;		//현재 출력할 문장을 시작 문장으로 세팅 = 시작 문장부터 출력하겠다
	
	//문장의 개수는 모르는 상태에서 반복을 진행한다
	//현재 문장이 있으면 반복하겠다 (문장 개수를 알수 없게 되었으므로 for는 쓸수 없게 됨)
	while (NULL != _current)
	{

		//switch (paragraph->current->_type)
		switch (_current->GetType())
		{
		case TEXT:
			_current->Print();
			break;
		case BRANCH:
			_current->Print();
			//요구사항 :
			//유저가 선택하기 전까지는 머물러 있어야 한다.
			//유저가  y or n을 선택하면 진행이 되어야 한다.
			//유저의 선택에 따라 다음 진행할 내용의 인덱스가 결정되어야 한다.
			while (true)
			{
				// || : or
				// && : and
				// == : equal
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return _current->GetSelectY();
				}
				else if ('n' == ch || 'N' == ch)
				{
					return _current->GetSelectN();
				}
				else if (27 == ch || 'q' == ch || 'Q' == ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			_current->Print();
			
			/*
			// 이건 그냥 내가 추가한거
			printf("다시 시작할까? Y or N");
			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1;
			}
			*/
					
		}

		_current = _current->GetNext();
	
	}

	return 0;
}


void sParagraphList::Create(int count)
{
	_count = count;
	_list = new sParagraph[_count];
}

void sParagraphList::AddStringToList(int pNo, sString* newString)
{
	_list[pNo].AddString(newString);
}

int sParagraphList::Print(int select)
{

	if (select < _count)
	{
		printf("\n");		//한줄 띄고
		return _list[select].Print();
	}
	return -1;
}

//숙제용
void sParagraphList::Destroy()
{
	delete[] _list;
}


/*
void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph)
{
	paragraphList->_list[paragraphList->_count] = *paragraph;
	paragraphList->_count++;
}
*/

