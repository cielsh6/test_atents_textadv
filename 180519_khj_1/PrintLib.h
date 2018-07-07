#pragma once

//전방 선언
class sString;

// sParagraph 캡슐화
class sParagraph
{
public:
	sParagraph();
	~sParagraph();


private:
	sString* _start;		//시작 문장
	sString* _current;	//현재 출력해야 할 문장

public:
	void AddString(sString* text);
	int Print();

};


class sParagraphList
{
private:
	int _count;
	sParagraph* _list;	// 나는 list 부터 하나씩 쓸거야

public:
	void Create(int count);
	void AddStringToList(int pNo, sString* newString);
	int Print(int select);
	
};



//얘는 현재 사용되는 곳이 없음
//void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);