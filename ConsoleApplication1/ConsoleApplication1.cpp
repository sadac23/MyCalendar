// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>

#define STR(var) #var   //引数にした変数を変数名を示す文字列リテラルとして返すマクロ関数
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

/* カレンダーのひと月分の情報を格納する構造体 */
struct CalData
{
	int year;				/* 年 */
	int month;				/* 月 */
	char *monthName;		/* 月名称 */
	Week startDaysOfWeek;	/* 開始曜日№ */
	int daysCount;			/* 日数 */
};


/* コマンドライン引数のチェックを行う */
extern int CheckArg(char *argv[]);

/* ひと月分のカレンダー情報を取得する */
extern CalData GetCalData(int year, int month);

/* ひと月分のカレンダーを表示する */
extern void DisplayCal(CalData *data);

/* ひと月分の日数を取得する */
extern int GetNumberOfDays(int year, int month);
	
/* 対象日付の曜日列挙体を取得する */
extern Week GetDayOfWeek(int year, int month, int day);
	
/* 対象日付の曜日列挙体を取得する */
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
	/* 引数チェック */
	if (CheckArg(argv) == -1) {
		printf("\nコマンドライン引数が有効ではありません。");
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

	/* 要素数チェック */
	if (sizeof argv < 4) {
		return -1;
	}

	year = argv[1];
	month = argv[2];
	num = argv[3];

	iyear = atoi(year);
	imonth = atoi(month);
	inum = atoi(num);

	/* 年チェック */
	if (2000 > iyear || iyear > 9999) {
		return -1;
	}

	/* 開始月チェック */
	if (1 > imonth || imonth > 12) {
		return -1;
	}

	/* 表示数チェック */
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

		/* ブランク出力 */
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

		/* 列カウントをリセット */
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

	// １月 と ２月 を前年の 13月 と 14月 として扱う
	if (month <= 2)
	{
		year -= 1;
		month += 12;
	}

	// 曜日番号を取得する
	//[0 = 日, 1 = 月, 2 = 火, 3 = 水, 4 = 木, 5 = 金, 6 = 土]
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
