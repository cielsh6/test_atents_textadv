#pragma once


enum eStringType
{
	TEXT,		//0
	BRANCH,		//1
	QUIT,		//2
};


class sString
{
public:
	sString();	// 생성자
	sString(const char* text, eStringType type, int selectY, int selectN);
	~sString();	// 해제자

private:	//데이터는 건드리지마
	eStringType _type;
	char _text[256];
	int _selectY;
	int _selectN;

	sString* _prev;		//이전 문장
	sString* _next;		//다음 문장

public:
	void Init(const char* text, eStringType type);
	void Init(const char* text, eStringType type, int selectY, int selectN);


public:		//얘는 바꿔도 돼
	virtual int Process();		//virtual  = 상속을 받은 자식 클래스에서는 다르게 작동시키고 싶어요.
	void Print();

	eStringType GetType() { return _type; }
	int GetSelectY() { return _selectY; }
	int GetSelectN() { return _selectN; }
	sString* GetNext() { return _next; }
	void SetNext(sString* next)
	{
		_next = next;
	}
	void InitNode(sString* prev, sString* next)
	{
		_prev = prev;
		_next = next;
	}
	
};