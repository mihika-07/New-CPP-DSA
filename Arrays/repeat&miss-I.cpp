#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n= nums.size();
        long long numsum=0;
        long long numsqsum=0;
        long long sum= n*(n+1)/2;
        long long sqsum= n*(n+1)*((2*n)+1)/6;
        for (int i=0; i<n; i++) {
            numsum= sum+ nums[i];
            numsqsum= numsqsum + ((long long)nums[i]*(long long)nums[i]);
        }
        long long val1= numsum- sum;
        long long val2= numsqsum- sqsum;
        val2= val2/val1;
        long long repeating= (val1 + val2)/2;
        long long missing= repeating - val1;
        return {(int)repeating, (int)missing};
    }
};