#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n= nums.size();
      vector<int> ans;
      int maxi=INT_MIN;
      for (int i=n-1; i>=0; i++) {
        if (nums[i]>maxi) {
            ans.push_back(nums[i]);
        }
        maxi=max(maxi, nums[i]);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};