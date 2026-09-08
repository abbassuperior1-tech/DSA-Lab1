#include <iostream>
#include "pascal.h"
using namespace std;

int main()
{
    // test case 1: n = 0
    vector<vector<int>> result1 = generatePascalTriangle(0);
    cout << "n = 0, number of rows = " << result1.size() << endl;

    // test case 2: n = 1
    vector<vector<int>> result2 = generatePascalTriangle(1);
    cout << "n = 1 output: ";
    for (int i = 0; i < result2[0].size(); i++)
        cout << result2[0][i] << " ";
    cout << endl;

    // test case 3: n = 5
    vector<vector<int>> result3 = generatePascalTriangle(5);
    cout << "n = 5 output:" << endl;
    for (int i = 0; i < result3.size(); i++)
    {
        for (int j = 0; j < result3[i].size(); j++)
        {
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }

    // checking if row 5 (last row) is 1 4 6 4 1
    int row5[] = {1, 4, 6, 4, 1};
    bool isCorrect = true;
    for (int i = 0; i < 5; i++)
    {
        if (result3[4][i] != row5[i])
        {
            isCorrect = false;
        }
    }

    if (isCorrect)
        cout << "Row 5 is correct" << endl;
    else
        cout << "Row 5 is wrong" << endl;

    return 0;
}