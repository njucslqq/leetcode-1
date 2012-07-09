//============================================================================
// Wildcard Matching
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*s=='\0'){
            if(*p=='\0')
                return true;
            else if(*p=='*')
                return isMatch(s, p+1);
            else
                return false;
        }
        else{
            if(*p=='\0')
                return false;
            else if(*p=='?' || *p==*s)
                return isMatch(s+1,p+1);
            else if(*p=='*')
                return isMatch(s+1,p) || isMatch(s,p+1);
            else
                return false;
        }
    }
};

int main() {
    return 0;
}