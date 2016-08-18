// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdlib.h>

/* �J�����_�[�̂Ђƌ����̏����i�[����\���� */
struct CalData
{
	int year;				/* �N */
	int month;				/* �� */
	char *monthName;		/* ������ */
	int startDaysOfWeek;	/* �J�n�j���� */
	int daysCount;			/* ���� */
};

/* �R�}���h���C�������̃`�F�b�N���s�� */
extern int CheckArg(char *argv[]);

/* �Ђƌ����̃J�����_�[�����擾���� */
extern CalData GetCalData(int year, int month);

/* �Ђƌ����̃J�����_�[��\������ */
extern void DisplayCal(CalData *data);

int main(int argc, char *argv[])
{
	CalData data;

	printf("test");

	printf("\nargc = %d", argc);
	printf("\nargv[0] = %s", argv[0]);
	printf("\nargv[1] = %s", argv[1]);
	printf("\nargv[2] = %s", argv[2]);
	printf("\nargv[3] = %s", argv[3]);

	if (CheckArg(argv) == -1) {
		printf("\n�R�}���h���C���������L���ł͂���܂���B");
		getchar();
		return -1;
	}

	data = GetCalData(atoi(argv[1]), atoi(argv[2]));

	printf("\ndata.year = %d", data.year);
	printf("\ndata.month = %d", data.month);
	printf("\ndata.monthName = %s", data.monthName);
	printf("\ndata.daysCount = %d", data.daysCount);
	printf("\ndata.startDaysOfWeek = %d", data.startDaysOfWeek);

	getchar();
	return 0;
}

int CheckArg(char * argv[])
{
	return 0;
}

CalData GetCalData(int year, int month)
{
	CalData data;
	data.year = year;
	data.month = month;
	data.daysCount = 30;
	data.startDaysOfWeek = 0;
	data.monthName = "a";

	return data;
}

void DisplayCal(CalData * data)
{
}
