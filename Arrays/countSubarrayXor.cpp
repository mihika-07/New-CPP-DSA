#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n= nums.size();
        map<int, int> mpp;
        mpp[0]=1;
        int xorr=0;
        int count=0;
        for (int i=0; i<n; i++) {
            xorr=xorr ^ nums[i];
            int x= k^xorr;
            count+= mpp[x];
            mpp[xorr]++;
        }
        return count;
    }
};