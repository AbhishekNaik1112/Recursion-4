// CombinationSum 2 - https://leetcode.com/problems/combination-sum-ii/description/

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30


#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index) {
    if (target == 0) {
        res.push_back(temp);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {

        if (i > index && candidates[i] == candidates[i - 1]) continue;


        if (candidates[i] > target) break;

        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i], res, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> findAll(vector<int>& candidates, int target) {
    sort(begin(candidates), end(candidates)); 
    vector<vector<int>> res;
    vector<int> temp;
    helper(candidates, target, res, temp, 0);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> sols = findAll(candidates, target);

    for (auto& sol : sols) {
        for (auto& i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}