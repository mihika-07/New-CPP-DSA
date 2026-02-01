#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.begin()+n);
        reverse(nums.begin(), nums.begin()+n);
    }
};