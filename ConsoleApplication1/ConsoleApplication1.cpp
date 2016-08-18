// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>

/* カレンダーのひと月分の情報を格納する構造体 */
struct CalData
{
	int year;				/* 年 */
	int month;				/* 月 */
	char *monthName;		/* 月名称 */
	int startDaysOfWeek;	/* 開始曜日№ */
	int daysCount;			/* 日数 */
};

/* コマンドライン引数のチェックを行う */
extern int CheckArg(char *argv[]);

/* ひと月分のカレンダー情報を取得する */
extern CalData GetCalData(int year, int month);

/* ひと月分のカレンダーを表示する */
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
		printf("\nコマンドライン引数が有効ではありません。");
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
