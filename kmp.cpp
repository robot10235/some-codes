#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
lc28: Given two strings needle and haystack, 
return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/

int strStr(string needle, string haystack) {
    // KMP 
    // find the next array
    int n = needle.size();
    int m = haystack.size();
    int i = 1;
    int j = 0;
    vector<int> next(n);

    // lc1392: A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
    // find the longest happy prefix
    while(i < n) {
        while(j > 0 && needle[i] != needle[j]) {
            j = next[j-1];
        }
        if(needle[i] == needle[j]) {
            ++j;
        }
        next[i] = j;
        ++i;
    }

    i = 0;
    j = 0;
    while(i < m) {
        while(j > 0 && haystack[i] != needle[j]) {
            j = next[j-1];
        }
        if(haystack[i] == needle[j]) {
            ++j;
        }
        if(j == n) {
            return i-j+1;
        }
        ++i;
    }
    return -1;
}

int main() {
    string needle = "ll";
    string haystack = "hello";
    cout << strStr(needle, haystack) << endl;
    return 0;
}
