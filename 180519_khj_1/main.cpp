#include <stdio.h>
#include <conio.h> //_getche()를 불러옴
#include <stdlib.h> //atoi(&)를 불러옴
#include "PrintLib.h" //내가 만든 헤더파일을 연결할때에는 쌍따옴표를 써야함
#include "sString.h"
#include "CSVLib.h"

void Save(int select)
{
	//파일을 연다
	FILE* fp = fopen("save.dat", "w+b");	// + : 없으면 만들고 열겠다는 이야기 , w : 쓰기 위해 만든다 , b : 바이너리 파일로 저장하겠다

	if (NULL == fp)
	{
		printf("\nFile can't open!");
		return;
	}

	// select 값을 파일에 기록하는 부분
	// |sizeof(int)*1|
	if (1 == fwrite(&select, sizeof(int), 1, fp))
	{
		printf("\nSave Success!");
	}
	else
	{
		printf("\nSave Failed....");
	}

	//다 썼으니까 닫아야 함
	fclose(fp);	
}

int Load()
{
	//파일을 연다
	FILE* fp = fopen("save.dat", "rb");	//읽기 위해 바이너리 파일을 연다

	if (NULL == fp)
	{
		printf("\nFile can't open!");
		return 0;
	}

	//저장된 select 값을 읽어온다
	int loadSelect = 0;
	if (1 == fread(&loadSelect, sizeof(int), 1, fp))
	{
		printf("\nLoad Success!");
	}
	else
	{
		printf("\nLoad Failed....");
	}

	//다 썼으니까 닫아야 함
	fclose(fp);

	return loadSelect;
}

int main(void) //메인 함수
{

	sParagraphList paragraphList;
	ParsingCSV("story.csv", &paragraphList);


	int textCount = 0;	//정수형 textCount에 0을 대입
	
	int select = 0; // 정수 select에 0을 대입

	// 요구사항
	// 로드를 하시겠습니까? Y or N
	// Y - 로드, N - 처음부터

	// 1. 문구 출력
	printf("\n로드를 하시겠습니까? Y or N");

	// 2. 입력
	char ch = _getche();
	if ('y' == ch || 'Y' == ch)
	{
		select = Load();
	}

	while (true) //값이 true일 때 반복되는 순환문 while
		{
			/*
			int nextSelect = 0;		//nextSelect에 정수 0을 대입

			if (select < paragraphList._count)
			{
				printf("\n");		//한줄 띄고
				//nextSelect = Print(&paragraphList.list[select]);
				nextSelect = paragraphList._list[select].Print();
			}
			else
			{
				break;
			}
			*/
			int nextSelect = paragraphList.Print(select);


			if (nextSelect < 0)		//nextSelect 값이 0보다 작으면 종료시킨다
			{
				break;
			}
			else	//nextSelect값이 0보다 크면
			{
				select = nextSelect;	//select 값에 nextSelect 값을 대입한다
			}

		}

		Save(select);


		/*
		//메모리 잡아다 썼으면 지워라
		for (int i = 0; i < paragraphList.count; i++)
		{
			//free(paragraphList.list[i].stringList);
			paragraphList.list[i]._current = paragraphList.list[i]._start;
			while (NULL != paragraphList.list[i]._current)
			{
				//다음 문장을 기억해 놓고
				sString* nextString = paragraphList.list[i]._current->GetNext();
				//현재 문장을 지운 후
				//free(paragraphList.list[i].current);
				delete paragraphList.list[i]._current;
				//현재 문장을 기억해 놓은 다음 문장으로 세팅
				paragraphList.list[i]._current = nextString;
				//다음 문장을 기억하지 않고 현재 문장을 지워버리면 다음 문장을 알 방법이 없다.
			}
		}
		*/
		
		
		//free(paragraphList.list);
		//delete[] paragraphList._list;		//[] :잡혀있는거 전부 지워라
		paragraphList.Destroy();	//delete[] paragraphList._list;	를 대체할 함수를 만들어라

		return 0;
		
}

