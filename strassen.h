#ifndef STRASSEN_H
#define STRASSEN_H
#include <vector>
using namespace std;

vector<vector<int>> strassenMultiply(vector<vector<int>> A, vector<vector<int>> B, int n);
vector<vector<int>> normalMultiply(vector<vector<int>> A, vector<vector<int>> B, int n);

#endif