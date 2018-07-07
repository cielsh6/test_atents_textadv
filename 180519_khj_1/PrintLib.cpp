#include <stdio.h>
#include <conio.h> //_getche()�� �ҷ���
#include <stdlib.h> //atoi(&)�� �ҷ���
#include <string.h> //strcpy �� �ҷ���
#include "sString.h"
#include "PrintLib.h"




void sParagraph::AddString(sString* string)		//�����Լ� 2��
{
	
	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���
	if (NULL == _current)
	{
		//ù ����
		_current = string;	//���� ���� ����
		string->InitNode(NULL, NULL);
		_start = string;
	}
	else
	{
		//ù ���� �ƴ�
		_current->SetNext(string);
		string->InitNode(_current, NULL);
		_current = string;
	}
}


int sParagraph::Print()
{
	/*
	for (int i = 0; i < paragraph->count; i++) //����ü�� �����ͷ� �ٲٸ� .�� ->�� �ٲ������ (.�� ����ü�϶�, ->�� �������϶� ���)
	{
		
		switch (paragraph->stringList[i].type)		//stringList[i] : i��° �ִ� ����
		{
		case TEXT:
			PrintText(paragraph->stringList[i].text);
			break;
		case BRANCH:
			PrintText(paragraph->stringList[i].text);
			//�䱸���� :
			//������ �����ϱ� �������� �ӹ��� �־�� �Ѵ�.
			//������  y or n�� �����ϸ� ������ �Ǿ�� �Ѵ�.
			//������ ���ÿ� ���� ���� ������ ������ �ε����� �����Ǿ�� �Ѵ�.
			while (true)
			{
				// || : or
				// && : and
				// == : equal
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return paragraph->stringList[i].selectY;
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->stringList[i].selectN;
				}
				else if (27 == ch || 'q'==ch || 'Q'==ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			PrintText(paragraph->stringList[i].text);

			// �̰� �׳� ���� �߰��Ѱ�
			printf("�ٽ� �����ұ�? Y or N");

			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1; 	//����
			}
	
		}
	}
	*/

	_current = _start;		//���� ����� ������ ���� �������� ���� = ���� ������� ����ϰڴ�
	
	//������ ������ �𸣴� ���¿��� �ݺ��� �����Ѵ�
	//���� ������ ������ �ݺ��ϰڴ� (���� ������ �˼� ���� �Ǿ����Ƿ� for�� ���� ���� ��)
	while (NULL != _current)
	{

		//switch (paragraph->current->_type)
		switch (_current->GetType())
		{
		case TEXT:
			_current->Print();
			break;
		case BRANCH:
			_current->Print();
			//�䱸���� :
			//������ �����ϱ� �������� �ӹ��� �־�� �Ѵ�.
			//������  y or n�� �����ϸ� ������ �Ǿ�� �Ѵ�.
			//������ ���ÿ� ���� ���� ������ ������ �ε����� �����Ǿ�� �Ѵ�.
			while (true)
			{
				// || : or
				// && : and
				// == : equal
				char ch = _getche();
				if ('y' == ch || 'Y' == ch)
				{
					return _current->GetSelectY();
				}
				else if ('n' == ch || 'N' == ch)
				{
					return _current->GetSelectN();
				}
				else if (27 == ch || 'q' == ch || 'Q' == ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			_current->Print();

			// �̰� �׳� ���� �߰��Ѱ�
			printf("�ٽ� �����ұ�? Y or N");

			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1; 	//����
			}

		}

		_current = _current->GetNext();
	
	}

	return 0;
}


void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph)
{
	paragraphList->list[paragraphList->count] = *paragraph;
	paragraphList->count++;
}

