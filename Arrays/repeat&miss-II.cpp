#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n= nums.size();
        int xr=0;
        for (int i=0; i<n; i++) {
            xr= xr^nums[i];
            xr= xr^ (i+1);
        }
        int bitno= 0;
        while (1) {
            if ((xr & (1<<bitno)) != 0) {
                break;
            }
            bitno++;
        }
        int zero=0;
        int one=0;
        for (int i=0; i<n; i++) {
            if ((nums[i] & (1<<bitno)) != 0) {
                one= one^nums[i];
            }
            else {
                zero= zero^nums[i];
            }
        }
        for (int i=1; i<=n; i++) {
            if ((i & (1<<bitno)) != 0) {
                one= one^i;
            }
            else {
                zero= zero^i;
            }
        }
        int count=0;
        for (int i=0; i<n; i++) {
            if (nums[i]==one) {
                count++;
            }
        }
        int missing=0;
        int repeating=0;
        if (count==2) {
            repeating= one;
            missing= zero;
        }
        else if (count==1) {
            repeating= zero;
            missing= one;
        }
        return {repeating, missing};
    }
};