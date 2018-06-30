#pragma once

//전방 선언
class sString;

struct sParagraph
{
	/*
	sString* stringList;
	int count;
	*/
	sString* start;		//시작 문장
	sString* current;	//현재 출력해야 할 문장
};


struct sParagraphList
{
	int count;
	//struct sParagraph list[256];
	struct sParagraph* list;	// 나는 list 부터 하나씩 쓸거야
};




int PrintParagraph(sParagraph* paragraph);

void AddStringToParagraph(sParagraph* paragraph, sString* text);
void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);