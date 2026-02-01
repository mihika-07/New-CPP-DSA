#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int last=nums[0];
        int n=nums.size();
        for (int j=0; j<n-1; j++) {
            nums[j]=nums[j+1];
        }
        nums[n-1]=last;
    }
};