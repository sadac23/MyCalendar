#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
	
		TEST_METHOD(CheckArgTest)
		{
			char *argv[4]{
				"hoge"
				, "2015"
				, "1"
				, "2"
			};

			Assert::AreEqual(0, CheckArg(argv));

			/* 年 */
			argv[1] = "9999";
			argv[2] = "1";
			argv[3] = "1";
			Assert::AreEqual(0, CheckArg(argv));

			argv[1] = "2000";
			Assert::AreEqual(0, CheckArg(argv));

			argv[1] = "10000";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[1] = "1999";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[1] = "a";
			Assert::AreEqual(-1, CheckArg(argv));

			/* 開始月 */
			argv[1] = "9999";
			argv[2] = "1";
			argv[3] = "1";
			Assert::AreEqual(0, CheckArg(argv));

			argv[2] = "12";
			Assert::AreEqual(0, CheckArg(argv));

			argv[2] = "0";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[2] = "13";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[2] = "a";
			Assert::AreEqual(-1, CheckArg(argv));

			/* 表示数 */
			argv[1] = "9999";
			argv[2] = "1";
			argv[3] = "1";
			Assert::AreEqual(0, CheckArg(argv));

			argv[3] = "12";
			Assert::AreEqual(0, CheckArg(argv));

			argv[3] = "0";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[3] = "13";
			Assert::AreEqual(-1, CheckArg(argv));

			argv[3] = "a";
			Assert::AreEqual(-1, CheckArg(argv));

		}

		TEST_METHOD(GetCalDataTest)
		{
			CalData data;

			data = GetCalData(2016, 8);

			Assert::AreEqual(data.year, 2016);
			Assert::AreEqual(data.month, 8);
			Assert::AreEqual(data.daysCount, 31);
			Assert::AreEqual((int)data.startDaysOfWeek, (int)Monday);
			Assert::AreEqual(data.monthName, "August");

			data = GetCalData(2016, 9);

			Assert::AreEqual(data.year, 2016);
			Assert::AreEqual(data.month, 9);
			Assert::AreEqual(data.daysCount, 30);
			Assert::AreEqual((int)data.startDaysOfWeek, (int)Thursday);
			Assert::AreEqual(data.monthName, "September");

			data = GetCalData(2015, 8);

			Assert::AreEqual(data.year, 2015);
			Assert::AreEqual(data.month, 8);
			Assert::AreEqual(data.daysCount, 31);
			Assert::AreEqual((int)data.startDaysOfWeek, (int)Saturday);
			Assert::AreEqual(data.monthName, "August");

		}

		TEST_METHOD(DisplayCalTest) {
			CalData data;

			data = GetCalData(2016, 1);
			DisplayCal(&data);
		}

	};
}