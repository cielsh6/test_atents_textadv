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
	sString * _start;		//시작 문장
	sString* _current;	//현재 출력해야 할 문장

public:
	void AddString(sString* text);
	int Process();

};