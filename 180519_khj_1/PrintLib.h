#pragma once

//���� ����
class sString;

// sParagraph ĸ��ȭ
struct sParagraph
{
	sString* _start;		//���� ����
	sString* _current;	//���� ����ؾ� �� ����

	void AddString(sString* text);
	int Print();

};


struct sParagraphList
{
	int count;
	struct sParagraph* list;	// ���� list ���� �ϳ��� ���ž�
};




//int PrintParagraph(sParagraph* paragraph);
//void AddStringToParagraph(sParagraph* paragraph, sString* text);
void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);