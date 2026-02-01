#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int binarySearch(int n) {
        int low=0;
        int high=n;
        int ans=0;
        while(low<=high) {
            int mid=(low+high)/2;
            if ((long long)mid*mid<=n) {
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
public:
    int mySqrt(int x) {
        return binarySearch(x);
    }
};