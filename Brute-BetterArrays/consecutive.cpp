#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int longest=1;
        int count=0;
        int smallest= INT_MIN;
        if (nums.size()==0) {
            return 0;
        }
        for (int i=0; i<n; i++) {
            if (smallest==nums[i]-1) {
                count++;
                smallest=nums[i];
            }
            else if (nums[i]!=smallest) {
                count=1;
                smallest=nums[i];
            }
            longest=max(longest, count);
        }
        return longest;
    }
};