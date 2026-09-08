#include <iostream>
#include "strassen.h"
using namespace std;

void printMat(vector<vector<int>> M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

bool checkSame(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != B[i][j])
                return false;
    return true;
}

int main()
{
    cout << "Lab submitted for Madam Arooj - Task 7" << endl;

    // test case 1: 2x2 multiplication
    vector<vector<int>> A2 = {{1, 2}, {3, 4}};
    vector<vector<int>> B2 = {{5, 6}, {7, 8}};

    vector<vector<int>> res1 = strassenMultiply(A2, B2, 2);
    vector<vector<int>> res1n = normalMultiply(A2, B2, 2);

    cout << "\nTest 1: 2x2 Matrix" << endl;
    cout << "Strassen result:" << endl;
    printMat(res1, 2);
    cout << "Normal result:" << endl;
    printMat(res1n, 2);
    cout << "Same? " << (checkSame(res1, res1n, 2) ? "yes matched" : "not matched, something wrong") << endl;

    // test case 2: 4x4 multiplication
    vector<vector<int>> A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    vector<vector<int>> B4 = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};

    vector<vector<int>> res2 = strassenMultiply(A4, B4, 4);
    vector<vector<int>> res2n = normalMultiply(A4, B4, 4);

    cout << "\nTest 2: 4x4 Matrix" << endl;
    cout << "Same? " << (checkSame(res2, res2n, 4) ? "yes matched" : "not matched") << endl;

    // test case 3: random values, 2x2 compared with naive
    vector<vector<int>> A3 = {{2, 0}, {1, 3}};
    vector<vector<int>> B3 = {{4, 1}, {2, 2}};

    vector<vector<int>> res3 = strassenMultiply(A3, B3, 2);
    vector<vector<int>> res3n = normalMultiply(A3, B3, 2);

    cout << "\nTest 3: random 2x2 vs naive" << endl;
    cout << "Same? " << (checkSame(res3, res3n, 2) ? "yes matched" : "not matched") << endl;

    return 0;
}