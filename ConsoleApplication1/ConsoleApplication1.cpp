// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdlib.h>

#define STR(var) #var   //�����ɂ����ϐ���ϐ��������������񃊃e�����Ƃ��ĕԂ��}�N���֐�
#define DAY_SEPARATOR " "

enum Week
{
	Sunday = 1
	, Monday = 2
	, Tuesday = 3
	, Wednesday = 4
	, Thursday = 5
	, Friday = 6
	, Saturday = 7
};

/* �J�����_�[�̂Ђƌ����̏����i�[����\���� */
struct CalData
{
	int year;				/* �N */
	int month;				/* �� */
	char *monthName;		/* ������ */
	Week startDaysOfWeek;	/* �J�n�j���� */
	int daysCount;			/* ���� */
};


/* �R�}���h���C�������̃`�F�b�N���s�� */
extern int CheckArg(char *argv[]);

/* �Ђƌ����̃J�����_�[�����擾���� */
extern CalData GetCalData(int year, int month);

/* �Ђƌ����̃J�����_�[��\������ */
extern void DisplayCal(CalData *data);

/* �Ђƌ����̓������擾���� */
extern int GetNumberOfDays(int year, int month);
	
/* �Ώۓ��t�̗j���񋓑̂��擾���� */
extern Week GetDayOfWeek(int year, int month, int day);
	
/* �Ώۓ��t�̗j���񋓑̂��擾���� */
extern char *GetMonthName(int month);

int main(int argc, char *argv[])
{
	CalData data;

/*
printf("test");

	printf("\nargc = %d", argc);
	printf("\nargv[0] = %s", argv[0]);
	printf("\nargv[1] = %s", argv[1]);
	printf("\nargv[2] = %s", argv[2]);
	printf("\nargv[3] = %s", argv[3]);

*/
	/* �����`�F�b�N */
	if (CheckArg(argv) == -1) {
		printf("\n�R�}���h���C���������L���ł͂���܂���B");
		getchar();
		return -1;
	}

	data = GetCalData(2015, 2);
	DisplayCal(&data);

	getchar();
	return 0;
}

int CheckArg(char *argv[])
{
	char *year, *month, *num;
	int iyear, imonth, inum;

	/* �v�f���`�F�b�N */
	if (sizeof argv < 4) {
		return -1;
	}

	year = argv[1];
	month = argv[2];
	num = argv[3];

	iyear = atoi(year);
	imonth = atoi(month);
	inum = atoi(num);

	/* �N�`�F�b�N */
	if (2000 > iyear || iyear > 9999) {
		return -1;
	}

	/* �J�n���`�F�b�N */
	if (1 > imonth || imonth > 12) {
		return -1;
	}

	/* �\�����`�F�b�N */
	if (1 > inum || inum > 12) {
		return -1;
	}

	return 0;
}

CalData GetCalData(int year, int month)
{
	CalData data;

	data.year = year;
	data.month = month;
	data.daysCount = GetNumberOfDays(year, month);
	data.startDaysOfWeek = GetDayOfWeek(year, month, 1);
	data.monthName = GetMonthName(month);

	return data;
}

/* Sample
"       January      "
"Su Mo Tu We Th Fr Sa"
"                   1"
" 2  3  4  5  6  7  8"
" 9 10 11 12 13 14 15"
"16 17 18 19 20 21 22"
"23 24 25 26 27 28 29"
"30 31               "
*/
void DisplayCal(CalData * data)
{
	int dayCount;
	int colCount;
	int weekCount;

	printf("       %s", data->monthName);
	printf("\nSu Mo Tu We Th Fr Sa");
	printf("\n");

	dayCount = 0;
	colCount = 0;
	weekCount = 0;
	while (dayCount < data->daysCount)
	{
		colCount++;
		dayCount++;
		weekCount++;

		/* �u�����N�o�� */
		if (dayCount == 1) {
			while (data->startDaysOfWeek != weekCount)
			{
				printf("  ");
				colCount++;
				weekCount++;
				if (colCount != 7) {
					printf(DAY_SEPARATOR);
				}
			}
		}

		printf("%2d", dayCount);

		/* ��J�E���g�����Z�b�g */
		if (colCount == 7) {
			printf("\n");
			colCount = 0;
			weekCount = 0;
		}
		else {
			printf(DAY_SEPARATOR);
		}
	}
}

int GetNumberOfDays(int year, int month){
	int numberOfDays;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		numberOfDays = 30;
	}
	else if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (isLeapYear)
			numberOfDays = 29;
		else
			numberOfDays = 28;
	}
	else {
		numberOfDays = 31;
	}
	return numberOfDays;
}

Week GetDayOfWeek(int year, int month, int day){
	int weekNumber;

	// �P�� �� �Q�� ��O�N�� 13�� �� 14�� �Ƃ��Ĉ���
	if (month <= 2)
	{
		year -= 1;
		month += 12;
	}

	// �j���ԍ����擾����
	//[0 = ��, 1 = ��, 2 = ��, 3 = ��, 4 = ��, 5 = ��, 6 = �y]
	weekNumber = (day + ((8 + (13 * month)) / 5) + (year + (year / 4) - (year / 100) + (year / 400))) % 7;

	switch (weekNumber)
	{
	case 0:
		return Sunday;
	case 1:
		return Monday;
	case 2:
		return Tuesday;
	case 3:
		return Wednesday;
	case 4:
		return Thursday;
	case 5:
		return Friday;
	case 6:
		return Saturday;
	default:
		return Monday;
	}

}

char *GetMonthName(int month)
{
	switch (month)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "";
	}
}
