#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    bool divisor(vector<int> &nums, int threshold, int mid) {
        int sum=0;
        for (int i=0; i<nums.size(); i++) {
            sum+=(nums[i] + mid - 1) / mid;
        }
        return sum<=threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int ans=-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if (divisor(nums,threshold, mid)) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};