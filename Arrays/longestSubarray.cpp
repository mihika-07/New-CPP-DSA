#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
       int left=0;
       int right=0;
       int sum=nums[0];
       int maxlen=0;
       while (right<nums.size()) {
        while (left<=right && sum>k) {
            sum=sum-nums[left];
            left++;
        }
        if (sum==k) {
            maxlen=max(maxlen, right-left+1);
        }
        right++;
        if (right<nums.size()){
            sum=sum+nums[right];
        }
       }
       return maxlen;
    }
};
