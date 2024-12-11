// Josephus - https://www.geeksforgeeks.org/problems/josephus-problem/1

// A total of n people are standing in a circle, and you are one of them playing a game. Starting from a person, k persons will be counted in order along the circle, and the kth person will be killed. Then the next k persons will be counted along the circle, and again the kth person will be killed. This cycle will continue until only a single person is left in the circle.

// If there are 5 people in the circle in the order A, B, C, D, and E, you will choose k=3. Starting from A, you will count A, B and C. C will be the 3rd person and will be killed. Then you will continue counting from D, E and then A. A will be third person and will be killed. 

// You will be given an array where the first element is the first person from whom the counting will start and the subsequent order of the people. You want to be the last one standing. Determine the index at which you should stand to survive the game. Return an integer denoting safe position. 

// Examples :

// Input: n = 3, k = 2
// Output: 3
// Explanation: There are 3 persons so skipping 1 person i.e 1st person 2nd person will be killed. Thus the safe position is 3.
// Input: n = 5, k = 3
// Output: 4
// Explanation: There are 5 persons so skipping 2 person i.e 3rd person will be killed. Thus the safe position is 4.
// Constraints:
// 1 <= n, k <= 20

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr, int k, int index) {
    if (arr.size() == 1) return arr[0];
    index = (index + k - 1) % arr.size();
    arr.erase(arr.begin() + index);
    return helper(arr, k, index);
}

int findAll(int n, int k) {
    vector<int> arr;
    for (int i = 1; i <= n; ++i) arr.push_back(i);
    int index = 0;
    return helper(arr, k, index);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout  << findAll(n, k);
    return 0;
}
