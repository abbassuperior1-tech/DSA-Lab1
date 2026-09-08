#include <iostream>
#include "find_indices.h"
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 2, 4, 2};
    vector<int> r1 = findIndices(arr1, 6, 2);
    cout << "Test 1 (multiple occurrences): ";
    for (int i : r1) cout << i << " ";
    cout << endl;

    int arr2[] = {1, 3, 5};
    vector<int> r2 = findIndices(arr2, 3, 9);
    cout << "Test 2 (key not present) size: " << r2.size() << endl;

    int arr3[] = {};
    vector<int> r3 = findIndices(arr3, 0, 5);
    cout << "Test 3 (empty array) size: " << r3.size() << endl;

    return 0;
}