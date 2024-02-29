#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_3_it/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestSTR)
        {
            const int rowCount = 3;
            const int colCount = 4;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 1;
            a[0][1] = 0;
            a[0][2] = -2;
            a[0][3] = 3;

            a[1][0] = -4;
            a[1][1] = 0;
            a[1][2] = 5;
            a[1][3] = 6;

            a[2][0] = 0;
            a[2][1] = -7;
            a[2][2] = 8;
            a[2][3] = -9;

            int result = STR(a, rowCount, colCount);

            Assert::AreEqual(0, result);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestCON)
        {
            int rowCount = 3;
            int colCount = 4;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            for (int i = 0; i < rowCount; ++i)
                for (int j = 0; j < colCount; ++j)
                    a[i][j] = 0;

            CON(a, rowCount, colCount);

            Assert::AreEqual(0, rowCount);
            Assert::AreEqual(0, colCount);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}