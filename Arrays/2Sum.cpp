#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string twoSum(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
     int n= nums.size();
     int j= n-1;
     int i=0;
     while (i<j) {
        if ((nums[i]+nums[j])<target) {
            i++;
        }
        else if ((nums[i]+nums[j])>target) {
            j--;
        }
        else {
            return "yes";
        }
     }
     return "no";
    }
};