/* Kadane's Algorithm */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxi= INT_MIN;
        int sum=0;
        int start=-1;
        int left=-1;
        int right=-1;
        for (int i=0; i<n; i++) {
            sum=sum+nums[i];
            if (sum>maxi) {
                maxi=sum;
                left=start;
                right=i;
            }
            if (sum<0) {
                sum=0;
                start=i+1;
            }
        }
        return {left, right};
    }
};