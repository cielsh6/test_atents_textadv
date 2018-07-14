#pragma once

class sString;
class sParagraph;


class sParagraphList
{
private:
	int _count;
	sParagraph* _list;	// 나는 list 부터 하나씩 쓸거야

public:
	void Create(int count);
	void AddStringToList(int pNo, sString* newString);
	int Process(int select);
	//숙제용
	void Destroy();

};

