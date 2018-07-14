#include <stdio.h> //FILE ����ü�� ���
#include <string.h> // token�� �и����ִ� �Լ��� ������ ���� ���� (strtok)
#include <stdlib.h>

#include "sString.h"
#include "CSVLib.h"
#include "sParagraphList.h"
#include "sStringText.h"
#include "sStringBranch.h"
#include "sStringQuit.h"



int CalcParagraphCount(FILE* fp)
{
	char buffer[1024];	//�����͸� buffer�� �����ϰڴ� (��������� �������)
	char* record = fgets(buffer, sizeof(buffer), fp);

	int prevNo = -1;
	int count = 0;

	while (1)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;

		char* token = strtok(record, ","); // ����, �޸��� �������� �� �и�����
		int pNo = atoi(token);

		if (pNo != prevNo)
		{
			prevNo = pNo;
			count++;
		}

	}
	fseek(fp, 0, SEEK_SET);	//0 : �� ù��° , SEEK_SET : �����ϴ� ��ġ

	return count;
}



void ParsingCSV(const char* fileName, sParagraphList* paragraphList)
{
	// ��ũ��Ʈ ��� 
	// 1. ������ ���� - ���Ͽ� �ִ� ������ ���� �غ� �Ѵ�.
	FILE* fp = fopen(fileName, "r");	// r = read, w = write (FILE ����ü�� ����ϱ� ���� �����Լ�)
	if (NULL == fp)
	{
		printf("\nError : File can't open");
		return;
	}

	// ������ ���ڸ��� ���ο� ������ � �ִ����� ����ҰŴ�
	int count = CalcParagraphCount(fp);
	paragraphList->Create(count);

	// 2. �Ľ� - ���Ͽ� �ִ� ������ �д´�

	char buffer[1024];	//�����͸� buffer�� �����ϰڴ� (��������� �������)
	char* record = fgets(buffer, sizeof(buffer), fp);		// ù �� �о��� - ��ŵ
	//printf("%s\n", record);

	int prevNo = -1;
	//paragraphList->count = 0;
	while (1)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;
		//printf("%s\n", record);

		char* token = strtok(record, ","); // ����, �޸��� �������� �� �и�����
		int pNo = atoi(token);
	
		token = strtok(NULL, ","); //Ÿ��
		eStringType type = (eStringType)atoi(token);

		token = strtok(NULL, ","); //����
		char* text = token;

		token = strtok(NULL, ","); // Y
		int selectY = atoi(token);

		token = strtok(NULL, ","); // N
		int selectN = atoi(token);
		
		if (pNo != prevNo)
		{
			//paragraphList->list[pNo]._current = NULL;		//�����ڿ��� ���ش�
			prevNo = pNo;
		}
		

		
		//sString* newString = new sString(text, type, selectY, selectN);
		sString* newString = NULL;
		switch (type)
		{
		case eStringType::TEXT:
			newString = new sStringText();
			break;
		case eStringType::BRANCH:
			newString = new sStringBranch();
			break;
		case eStringType::QUIT:
			newString = new sStringQuit();
			break;
		}
		newString->Init(text, type, selectY, selectN);
		paragraphList->AddStringToList(pNo, newString);


	}

	// 3. ���� �����͸� �����Ѵ�.

	// 4. ������ �ݴ´� - ������ �ٽ� ���� �� ���� ���·� �����.
	fclose(fp); //(FILE ����ü�� ����ϱ� ���� �����Լ�)
}