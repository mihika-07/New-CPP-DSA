#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        map<int, int> presummap;
        presummap[0]=1;
        int sum=0;
        int count=0;
        for (int i=0; i<n; i++) {
            sum+= nums[i];
            int remove= sum-k;
            count+= presummap[remove];
            presummap[sum]+=1;
        }
        return count;
    }
};