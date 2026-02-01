#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int suffix=1;
        int prefix=1;
        int ans= INT_MIN;
        for (int i=0; i<n; i++) {
            if (suffix==0) {
                suffix=1;
            }
            if (prefix==0) {
                prefix=1;
            }
            suffix= suffix* nums[n-1-i];
            prefix= prefix* nums[i];
            ans= max(ans, max(prefix, suffix));
        }
        return ans;
    }
};