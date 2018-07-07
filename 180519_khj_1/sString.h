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
	sString();	// ������
	sString(const char* text, eStringType type, int selectY, int selectN);
	~sString();	// ������

private:	//�����ʹ� �ǵ帮����
	eStringType _type;
	char _text[256];
	int _selectY;
	int _selectN;

	sString* _prev;		//���� ����
	sString* _next;		//���� ����

private:
	void Init(const char* text, eStringType type);
	void Init(const char* text, eStringType type, int selectY, int selectN);


public:		//��� �ٲ㵵 ��
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