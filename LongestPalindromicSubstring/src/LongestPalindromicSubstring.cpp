//============================================================================
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.length();
        string T = "^";
        for (int i = 0; i < m; i++)
            T += "#" + s.substr(i, 1);
        T += "#$";
        int n = T.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2*C-i; // equals to i' = C - (i-C)

            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;

            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        delete[] P;

        return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
};

int main() {
	return 0;
}
