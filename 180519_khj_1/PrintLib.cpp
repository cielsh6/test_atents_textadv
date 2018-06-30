#include <stdio.h>
#include <conio.h> //_getche()�� �ҷ���
#include <stdlib.h> //atoi(&)�� �ҷ���
#include <string.h> //strcpy �� �ҷ���
#include "sString.h"
#include "PrintLib.h"




void AddStringToParagraph(sParagraph* paragraph, sString* string)		//�����Լ� 2��
{
	/*
	paragraph->stringList[paragraph->count] = *text;		
	paragraph->count++;		
	*/
	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���
	if (NULL == paragraph->current)
	{
		//ù ����
		paragraph->current = string;	//���� ���� ����
		//string->_prev = NULL;
		//string->_next = NULL;
		string->InitNode(NULL, NULL);
		paragraph->start = string;
	}
	else
	{
		//ù ���� �ƴ�
		//paragraph->current->_next = string;
		paragraph->current->SetNext(string);
		//string->_prev = paragraph->current;
		//string->_next = NULL;
		string->InitNode(paragraph->current, NULL);
		paragraph->current = string;
	}
}


int PrintParagraph(sParagraph* paragraph)
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

	paragraph->current = paragraph->start;		//���� ����� ������ ���� �������� ���� = ���� ������� ����ϰڴ�
	
	//������ ������ �𸣴� ���¿��� �ݺ��� �����Ѵ�
	//���� ������ ������ �ݺ��ϰڴ� (���� ������ �˼� ���� �Ǿ����Ƿ� for�� ���� ���� ��)
	while (NULL != paragraph->current)
	{

		//switch (paragraph->current->_type)
		switch (paragraph->current->GetType())
		{
		case TEXT:
			paragraph->current->Print();
			break;
		case BRANCH:
			paragraph->current->Print();
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
					return paragraph->current->GetSelectY();
				}
				else if ('n' == ch || 'N' == ch)
				{
					return paragraph->current->GetSelectN();
				}
				else if (27 == ch || 'q' == ch || 'Q' == ch)	//27 : ESC
				{
					return -1;
				}
			}
			break;
		case QUIT:
			paragraph->current->Print();

			// �̰� �׳� ���� �߰��Ѱ�
			printf("�ٽ� �����ұ�? Y or N");

			char ch = _getche();
			if ('n' == ch || 'N' == ch)
			{
				return -1; 	//����
			}

		}

		paragraph->current = paragraph->current->GetNext();
	
	}

	return 0;
}


void AddParagraphToList(sParagraphList* paragraphList, sParagraph* paragraph)
{
	paragraphList->list[paragraphList->count] = *paragraph;
	paragraphList->count++;
}

