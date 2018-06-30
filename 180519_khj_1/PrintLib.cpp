#include <stdio.h>
#include <conio.h> //_getche()를 불러옴
#include <stdlib.h> //atoi(&)를 불러옴
#include <string.h> //strcpy 를 불러옴
#include "sString.h"
#include "PrintLib.h"




void AddStringToParagraph(sParagraph* paragraph, sString* string)		//도움함수 2번
{
	/*
	paragraph->stringList[paragraph->count] = *text;		
	paragraph->count++;		
	*/
	// 첫 문장일 때, 첫 문장이 아닐 때 세팅이 다르다
	if (NULL == paragraph->current)
	{
		//첫 문장
		paragraph->current = string;	//현재 문장 세팅
		//string->_prev = NULL;
		//string->_next = NULL;
		string->InitNode(NULL, NULL);
		paragraph->start = string;
	}
	else
	{
		//첫 문장 아님
		//paragraph->current->_next = string;
		paragraph->current->SetNext(string);
		//string->_prev = paragraph->current;
		//string->_next = NULL;
		string->InitNode(paragraph->current, NULL);
		paragraph->current = string;
	}
}


int PrintParagraph(sParagraph* paragraph)
{
	/*
	for (int i = 0; i < paragraph->count; i++) //구조체를 포인터로 바꾸면 .을 ->로 바꿔줘야함 (.은 구조체일때, ->는 포인터일때 사용)
	{
		
		switch (paragraph->stringList[i].type)		//stringList[i] : i번째 있는 문장
		{
		case TEXT:
			PrintText(paragraph->stringList[i].text);
			break;
		case BRANCH:
			PrintText(paragraph->stringList[i].text);
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
					return paragraph->stringList[i].selectY;
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->stringList[i].selectN;
				}
				else if (27 == ch || 'q'==ch || 'Q'==ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			PrintText(paragraph->stringList[i].text);

			// 이건 그냥 내가 추가한거
			printf("다시 시작할까? Y or N");

			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1; 	//종료
			}
	
		}
	}
	*/

	paragraph->current = paragraph->start;		//현재 출력할 문장을 시작 문장으로 세팅 = 시작 문장부터 출력하겠다
	
	//문장의 개수는 모르는 상태에서 반복을 진행한다
	//현재 문장이 있으면 반복하겠다 (문장 개수를 알수 없게 되었으므로 for는 쓸수 없게 됨)
	while (NULL != paragraph->current)
	{

		//switch (paragraph->current->_type)
		switch (paragraph->current->GetType())
		{
		case TEXT:
			paragraph->current->Print();
			break;
		case BRANCH:
			paragraph->current->Print();
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
					return paragraph->current->GetSelectY();
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->current->GetSelectN();
				}
				else if (27 == ch || 'q' == ch || 'Q' == ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			paragraph->current->Print();

			// 이건 그냥 내가 추가한거
			printf("다시 시작할까? Y or N");

			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1; 	//종료
			}

		}

		paragraph->current = paragraph->current->GetNext();
	
	}

	return 0;
}


void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph)
{
	paragraphList->list[paragraphList->count] = *paragraph;
	paragraphList->count++;
}

