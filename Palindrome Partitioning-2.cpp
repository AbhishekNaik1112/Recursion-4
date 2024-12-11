// Palindrome Partitioning-2 - https://leetcode.com/problems/palindrome-partitioning-ii/description/

// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters only.


#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> memo; //using memo - saving previous results

bool checker(string& s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int helper(string& s, int index) {
    if (index >= n)
        return 0;

    if (memo[index] != -1)
        return memo[index];

    int minCuts = INT_MAX;
    for (int i = index; i < n; i++) {
        if (checker(s, index, i)) {
            int cuts = 1 + helper(s, i + 1);
            minCuts = min(minCuts, cuts);
        }
    }
    return memo[index] = minCuts;
}

int findAll(string s) {
    n = s.size();
    memo.assign(n, -1);
    return helper(s, 0) - 1;
}

int main() {
    string s;
    cin>>s;
    cout << findAll(s) << endl;
    return 0;
}
