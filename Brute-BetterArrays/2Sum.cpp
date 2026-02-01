#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        map <int, int> index;
        for (int i=0; i<n; i++) {
            if (index.find(target-nums[i])!=index.end()) {
                return {index[target-nums[i]],i};
            }
            else {
                index[nums[i]]= i;
            }
        }
        return {};
    }
};