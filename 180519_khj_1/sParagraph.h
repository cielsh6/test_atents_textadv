#pragma once
//���� ����
class sString;

// sParagraph ĸ��ȭ
class sParagraph
{
public:
	sParagraph();
	~sParagraph();


private:
	sString * _start;		//���� ����
	sString* _current;	//���� ����ؾ� �� ����

public:
	void AddString(sString* text);
	int Process();

};