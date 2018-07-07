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
	sString* _start;		//���� ����
	sString* _current;	//���� ����ؾ� �� ����

public:
	void AddString(sString* text);
	int Print();

};


class sParagraphList
{
private:
	int _count;
	sParagraph* _list;	// ���� list ���� �ϳ��� ���ž�

public:
	void Create(int count);
	void AddStringToList(int pNo, sString* newString);
	int Print(int select);
	
};



//��� ���� ���Ǵ� ���� ����
//void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);