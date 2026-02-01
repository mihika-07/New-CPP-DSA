#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int r) {
        vector<int> ans;
        long long start=1;
        ans.push_back(1);
        for (int i=1; i<r; i++) {
            start= start * (r-i)/ (i);
            ans.push_back(start);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=1; i<=numRows; i++) {
            vector<int> temp= generateRow(i);
            res.push_back(temp);
        }
        return res;
    }
};