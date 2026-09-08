#include "pascal.h"
#include <iostream>
using namespace std;

vector<vector<int>> generatePascalTriangle(int n)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                row.push_back(1);
            }
            else
            {
                int val = triangle[i - 1][j - 1] + triangle[i - 1][j];
                row.push_back(val);
            }
        }

        triangle.push_back(row);
    }

    return triangle;
}