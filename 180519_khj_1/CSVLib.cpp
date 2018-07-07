#include <stdio.h> //FILE 구조체를 사용
#include <string.h> // token을 분리해주는 함수를 가져다 쓰기 위함 (strtok)
#include <stdlib.h>
#include "PrintLib.h"
#include "sString.h"
#include "CSVLib.h"

int CalcParagraphCount(FILE* fp)
{
	char buffer[1024];	//데이터를 buffer에 저장하겠다 (저장공간을 만들어줌)
	char* record = fgets(buffer, sizeof(buffer), fp);

	int prevNo = -1;
	int count = 0;

	while (1)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;

		char* token = strtok(record, ","); // 문단, 콤마를 기준으로 다 분리해줘
		int pNo = atoi(token);

		if (pNo != prevNo)
		{
			prevNo = pNo;
			count++;
		}

	}
	fseek(fp, 0, SEEK_SET);	//0 : 맨 첫번째 , SEEK_SET : 시작하는 위치

	return count;
}



void ParsingCSV(const char* fileName, sParagraphList* paragraphList)
{
	// 스크립트 사용 
	// 1. 파일을 연다 - 파일에 있는 내용을 읽을 준비를 한다.
	FILE* fp = fopen(fileName, "r");	// r = read, w = write (FILE 구조체를 사용하기 위한 도움함수)
	if (NULL == fp)
	{
		printf("\nError : File can't open");
		return;
	}

	// 파일을 열자마자 내부에 문단이 몇개 있는지를 계산할거다
	paragraphList->count = CalcParagraphCount(fp);
	paragraphList->list = (sParagraph*)malloc(paragraphList->count * sizeof(sParagraph));

	// 2. 파싱 - 파일에 있는 내용을 읽는다

	char buffer[1024];	//데이터를 buffer에 저장하겠다 (저장공간을 만들어줌)
	char* record = fgets(buffer, sizeof(buffer), fp);		// 첫 줄 읽었고 - 스킵
	//printf("%s\n", record);

	int prevNo = -1;
	//paragraphList->count = 0;
	while (1)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;
		//printf("%s\n", record);

		char* token = strtok(record, ","); // 문단, 콤마를 기준으로 다 분리해줘
		int pNo = atoi(token);
	
		token = strtok(NULL, ","); //타입
		eStringType type = (eStringType)atoi(token);

		token = strtok(NULL, ","); //내용
		char* text = token;

		token = strtok(NULL, ","); // Y
		int selectY = atoi(token);

		token = strtok(NULL, ","); // N
		int selectN = atoi(token);
		
		if (pNo != prevNo)
		{
			paragraphList->list[pNo]._current = NULL;
			prevNo = pNo;
		}
		



		//struct  sString* newString = (sString*)malloc(sizeof(sString));
		//sString* newString = new sString();
		//newString->Init(text, type, selectY, selectN);
		sString* newString = new sString(text, type, selectY, selectN);
		//AddString(&paragraphList->list[pNo], newString);
		paragraphList->list[pNo].AddString(newString);


	}

	// 3. 게임 데이터를 구성한다.

	// 4. 파일을 닫는다 - 파일을 다시 읽을 수 없는 상태로 만든다.
	fclose(fp); //(FILE 구조체를 사용하기 위한 도움함수)
}