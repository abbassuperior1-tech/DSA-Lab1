#include "find_indices.h"
vector<int> findIndices(int arr[], int n, int key) {
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            result.push_back(i);
        }
    }
    return result;
}