#pragma once

//���� ����
class sString;

struct sParagraph
{
	/*
	sString* stringList;
	int count;
	*/
	sString* start;		//���� ����
	sString* current;	//���� ����ؾ� �� ����
};


struct sParagraphList
{
	int count;
	//struct sParagraph list[256];
	struct sParagraph* list;	// ���� list ���� �ϳ��� ���ž�
};




int PrintParagraph(sParagraph* paragraph);

void AddStringToParagraph(sParagraph* paragraph, sString* text);
void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph);