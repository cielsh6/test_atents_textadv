#pragma once

class sString;
class sParagraph;


class sParagraphList
{
private:
	int _count;
	sParagraph* _list;	// ���� list ���� �ϳ��� ���ž�

public:
	void Create(int count);
	void AddStringToList(int pNo, sString* newString);
	int Process(int select);
	//������
	void Destroy();

};

