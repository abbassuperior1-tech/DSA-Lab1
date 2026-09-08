#include "pattern_match.h"

int findPattern(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    //  i used thus logic: Empty pattern is considered to match at index 0
    if (m == 0) {
        return 0;
    }

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; // full pattenr matched starting at i
        }
    }

    return -1; //-1 will printt if  patern not found
}