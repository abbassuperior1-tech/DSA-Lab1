#include "strassen.h"
using namespace std;

// normal way of multiplying, we learned this in DSA class
vector<vector<int>> normalMultiply(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    return C;
}

// add two matrix
vector<vector<int>> addMatrix(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// subtract two matrix
vector<vector<int>> subMatrix(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

vector<vector<int>> strassenMultiply(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    // base case, agar 1x1 hai to bs multiply kr do
    if (n == 1)
    {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;

    // dividing matrix A into 4 parts
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    // dividing matrix B into 4 parts
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // 7 multiplications (strassen ka trick, sir ne yehi samjhaya tha class me)
    vector<vector<int>> M1 = strassenMultiply(addMatrix(A11, A22, newSize), addMatrix(B11, B22, newSize), newSize);
    vector<vector<int>> M2 = strassenMultiply(addMatrix(A21, A22, newSize), B11, newSize);
    vector<vector<int>> M3 = strassenMultiply(A11, subMatrix(B12, B22, newSize), newSize);
    vector<vector<int>> M4 = strassenMultiply(A22, subMatrix(B21, B11, newSize), newSize);
    vector<vector<int>> M5 = strassenMultiply(addMatrix(A11, A12, newSize), B22, newSize);
    vector<vector<int>> M6 = strassenMultiply(subMatrix(A21, A11, newSize), addMatrix(B11, B12, newSize), newSize);
    vector<vector<int>> M7 = strassenMultiply(subMatrix(A12, A22, newSize), addMatrix(B21, B22, newSize), newSize);

    // combining results
    vector<vector<int>> C11 = addMatrix(subMatrix(addMatrix(M1, M4, newSize), M5, newSize), M7, newSize);
    vector<vector<int>> C12 = addMatrix(M3, M5, newSize);
    vector<vector<int>> C21 = addMatrix(M2, M4, newSize);
    vector<vector<int>> C22 = addMatrix(subMatrix(addMatrix(M1, M3, newSize), M2, newSize), M6, newSize);

    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}