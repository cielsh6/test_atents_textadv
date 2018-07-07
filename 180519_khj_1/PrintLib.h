#pragma once

//전방 선언
class sString;

// sParagraph 캡슐화
struct sParagraph
{
	sString* _start;		//시작 문장
	sString* _current;	//현재 출력해야 할 문장

	void AddString(sString* text);
	int Print();

};


struct sParagraphList
{
	int count;
	struct sParagraph* list;	// 나는 list 부터 하나씩 쓸거야
};




//int PrintParagraph(sParagraph* paragraph);
//void AddStringToParagraph(sParagraph* paragraph, sString* text);
void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);