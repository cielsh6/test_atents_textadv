#include <stdio.h> //FILE ����ü�� ���
#include <string.h> // token�� �и����ִ� �Լ��� ������ ���� ���� (strtok)
#include <stdlib.h>
#include "PrintLib.h"
#include "sString.h"
#include "CSVLib.h"

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

/* ������ �� �ʿ䰡 ���� ������ ��� �ʿ䰡 ����
void CreateParagraphStringList(sParagraph* paragraph, FILE* fp)
{
	char buffer[1024];	//�����͸� buffer�� �����ϰڴ� (��������� �������)
	char* record = fgets(buffer, sizeof(buffer), fp);

	int prevNo = 0;
	int count = 0;

	while (1)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
		{
			paragraph[prevNo].stringList = (sString*)malloc(count * sizeof(sString));
			break;
		}
		
		char* token = strtok(record, ","); // ����, �޸��� �������� �� �и�����
		int pNo = atoi(token);

		if (pNo != prevNo)		//������ �ٲ�� �κ�
		{
			paragraph[prevNo].stringList = (sString*)malloc(count * sizeof(sString));

			prevNo = pNo;
			count = 0;
		}

		count++;
	}
	fseek(fp, 0, SEEK_SET);
}
*/


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
	paragraphList->count = CalcParagraphCount(fp);
	paragraphList->list = (sParagraph*)malloc(paragraphList->count * sizeof(sParagraph));

	//CreateParagraphStringList(paragraphList->list, fp);

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
			//������ �ٲ����
			//paragraphList->list[pNo].count = 0;
			paragraphList->list[pNo].current = NULL;
			//paragraphList->count++;
			prevNo = pNo;
		}
		


		//struct sString newString;
		//InitString(&newString, text, type, selectY, selectN);
		//AddStringToParagraph(&paragraphList->list[pNo], &newString);
		struct  sString* newString = (sString*)malloc(sizeof(sString));
		newString->Init(text, type, selectY, selectN);
		AddStringToParagraph(&paragraphList->list[pNo], newString);

		/*
		 while (NULL != token)
		 {
		   printf("Token %s\n", token);
		   token = strtok(NULL, ",");
		 }
		 */

	}

	// 3. ���� �����͸� �����Ѵ�.

	// 4. ������ �ݴ´� - ������ �ٽ� ���� �� ���� ���·� �����.
	fclose(fp); //(FILE ����ü�� ����ϱ� ���� �����Լ�)
}