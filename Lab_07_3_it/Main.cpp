#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** a, int colCount, int row1, int row2) {
    for (int i = 0; i < colCount; ++i)
    {
        int temp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = temp;
    }
}

int STR(int** a, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; ++i)
        for (int j = 0; j < colCount; ++j)
            if (a[i][j] > 0)
                return i;
    return -1;
}

void CON(int** a, int& rowCount, int& colCount) {
    for (int i = 0; i < rowCount; ++i) {
        bool nonZeroRow = false;
        for (int j = 0; j < colCount; ++j)
            if (a[i][j] != 0) {
                nonZeroRow = true;
                break;
            }

        if (!nonZeroRow) {
            for (int k = i; k < rowCount - 1; ++k)
                Change(a, colCount, k, k + 1);
            --rowCount;
            --i;
        }
    }

    for (int j = 0; j < colCount; ++j) {
        bool nonZeroCol = false;
        for (int i = 0; i < rowCount; ++i)
            if (a[i][j] != 0) {
                nonZeroCol = true;
                break;
            }

        if (!nonZeroCol) {
            for (int k = j; k < colCount - 1; ++k)
                for (int i = 0; i < rowCount; ++i)
                    a[i][k] = a[i][k + 1];
            --colCount;
            --j;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    int Low = -1;
    int High = 0;
    int rowCount;
    int colCount;
    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int PositiveElement = STR(a, rowCount, colCount);
    if (PositiveElement != -1)
        cout << "The first line containing a positive element: " << PositiveElement << endl;
    else
        cout << "No positive element found in any row." << endl;

    CON(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;

}