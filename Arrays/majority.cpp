/* Moore's Voting Algorithm */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n= nums.size();
      int el=-1;
      int count=0;
      for (int i=0; i<n; i++) {
        if (count==0) {
            el=i;
        }
        if (nums[el]==nums[i]) {
            count++;
        }
        else if (nums[el]!=nums[i]) {
            count--;
        }
      }
      int verify=0;
      for (int i=0; i<n; i++) {
        if (nums[el]==nums[i]) {
            verify++;
        }
      }
      if (verify>n/2) {
        return nums[el];
      }
      return -1;
    }
};