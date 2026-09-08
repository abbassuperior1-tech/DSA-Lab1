#include <iostream>
#include "mode.h"
using namespace std;

int main()
{
    // test case 1: unique mode
    int arr1[] = {1, 2, 2, 3, 4};
    cout << "Sir Fahad Satti - Test 1 (unique mode): " << findMode(arr1, 5) << endl;

    // test case 2: multiple modes
    int arr2[] = {1, 1, 2, 2, 3};
    cout << "Sir Fahad Satti - Test 2 (multiple modes, returns one of them): " << findMode(arr2, 5) << endl;

    // test case 3: empty array
    int arr3[] = {};
    cout << "Sir Fahad Satti - Test 3 (empty array): " << findMode(arr3, 0) << endl;

    return 0;
}