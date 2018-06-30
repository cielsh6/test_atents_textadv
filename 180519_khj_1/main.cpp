#include <stdio.h>
#include <conio.h> //_getche()�� �ҷ���
#include <stdlib.h> //atoi(&)�� �ҷ���
#include "PrintLib.h" //���� ���� ��������� �����Ҷ����� �ֵ���ǥ�� �����
#include "sString.h"
#include "CSVLib.h"

void Save(int select)
{
	//������ ����
	FILE* fp = fopen("save.dat", "w+b");	// + : ������ ����� ���ڴٴ� �̾߱� , w : ���� ���� ����� , b : ���̳ʸ� ���Ϸ� �����ϰڴ�

	if (NULL == fp)
	{
		printf("\nFile can't open!");
		return;
	}

	// select ���� ���Ͽ� ����ϴ� �κ�
	// |sizeof(int)*1|
	if (1 == fwrite(&select, sizeof(int), 1, fp))
	{
		printf("\nSave Success!");
	}
	else
	{
		printf("\nSave Failed....");
	}

	//�� �����ϱ� �ݾƾ� ��
	fclose(fp);	
}

int Load()
{
	//������ ����
	FILE* fp = fopen("save.dat", "rb");	//�б� ���� ���̳ʸ� ������ ����

	if (NULL == fp)
	{
		printf("\nFile can't open!");
		return 0;
	}

	//����� select ���� �о�´�
	int loadSelect = 0;
	if (1 == fread(&loadSelect, sizeof(int), 1, fp))
	{
		printf("\nLoad Success!");
	}
	else
	{
		printf("\nLoad Failed....");
	}

	//�� �����ϱ� �ݾƾ� ��
	fclose(fp);

	return loadSelect;
}

int main(void) //���� �Լ�
{

	struct sParagraphList paragraphList;
	ParsingCSV("story.csv", &paragraphList);


	int textCount = 0;	//������ textCount�� 0�� ����
	
	int select = 0; // ���� select�� 0�� ����

	// �䱸����
	// �ε带 �Ͻðڽ��ϱ�? Y or N
	// Y - �ε�, N - ó������

	// 1. ���� ���
	printf("\n�ε带 �Ͻðڽ��ϱ�? Y or N");

	// 2. �Է�
	char ch = _getche();
	if ('y' == ch || 'Y' == ch)
	{
		select = Load();
	}

	while (true) //���� true�� �� �ݺ��Ǵ� ��ȯ�� while
		{
		
			int nextSelect = 0;		//nextSelect�� ���� 0�� ����

			if (select < paragraphList.count)
			{
				printf("\n");		//���� ���
				nextSelect = PrintParagraph(&paragraphList.list[select]);
			}
			else //select���� 3���� ũ�� ���
			{
				//PrintText("������ ����");
				break;
			}

			if (nextSelect < 0)		//nextSelect ���� 0���� ������ �����Ų��
			{
				break;
			}
			else	//nextSelect���� 0���� ũ��
			{
				select = nextSelect;	//select ���� nextSelect ���� �����Ѵ�
			}

		}

		Save(select);

		//�޸� ��ƴ� ������ ������
		for (int i = 0; i < paragraphList.count; i++)
		{
			//free(paragraphList.list[i].stringList);
			paragraphList.list[i].current = paragraphList.list[i].start;
			while (NULL != paragraphList.list[i].current)
			{
				//���� ������ ����� ����
				sString* nextString = paragraphList.list[i].current->GetNext();
				//���� ������ ���� ��
				free(paragraphList.list[i].current);
				//���� ������ ����� ���� ���� �������� ����
				paragraphList.list[i].current = nextString;
				//���� ������ ������� �ʰ� ���� ������ ���������� ���� ������ �� ����� ����.
			}
		}
		
		free(paragraphList.list);

		return 0;
		
}
