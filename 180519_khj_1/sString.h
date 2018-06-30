#pragma once


enum eStringType
{
	TEXT,		//0
	BRANCH,		//1
	QUIT,		//2
};


class sString
{
private:	//데이터는 건드리지마
	eStringType _type;
	char _text[256];
	int _selectY;
	int _selectN;

	sString* _prev;		//이전 문장
	sString* _next;		//다음 문장

public:		//얘는 바꿔도 돼
	void Init(const char* text, eStringType type);
	void Init(const char* text, eStringType type, int selectY, int selectN);
	void Print();

	eStringType GetType() { return _type; }
	int GetSelectY() { return _selectY; }
	int GetSelectN() { return _selectN; }
	sString* GetNext() { return _next; }
	void SetNext(sString* next) { _next = next; }
	void InitNode(sString* prev, sString* next)
	{
		_prev = prev;
		_next = next;
	}
	
};