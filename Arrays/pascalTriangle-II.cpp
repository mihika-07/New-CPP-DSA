#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int start= 1;
        long long j=1;
        ans.push_back(1);
        for (int i=1; i<rowIndex+1; i++) {
            j= j * (rowIndex+1-i)/ (i);
            ans.push_back(j);
        }
        return ans;
    }
};