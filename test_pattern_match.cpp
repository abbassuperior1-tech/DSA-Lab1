#include <iostream>
#include "pattern_match.h"
using namespace std;

int main() {
    // Test 1: pattern at the beginning
    cout << "Test 1 (pattern at beginning): "
         << findPattern("Arooj Mam teaches DSA", "Arooj") << endl;

    // Test 2: pattern at the end
    cout << "Test 2 (pattern at end): "
         << findPattern("Arooj Mam teaches DSA", "DSA") << endl;

    // Test 3: pattern not present
    cout << "Test 3 (pattern not present): "
         << findPattern("Arooj Mam teaches DSA", "xyz") << endl;

    // Test 4: empty pattern
    cout << "Test 4 (empty pattern): "
         << findPattern("Arooj Mam teaches DSA", "") << endl;

    return 0;
}