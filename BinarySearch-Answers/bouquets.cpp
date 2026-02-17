#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    bool canbouquet(vector<int>& bloomday, int m, int k, int mid) {
        int count=0;
        int flowers=0;
        for (int i=0; i<bloomday.size(); i++) {
            if (bloomday[i]<=mid) {
                flowers++;
                if (flowers==k) {
                    count++;
                    flowers=0;
                }
            }
            else {
                flowers=0;
            }
        }
        return count>=m;
    }

    int binarySearch(vector<int>& bloomday, int m, int k) {
        int low=*min_element(bloomday.begin(), bloomday.end());
        int high=*max_element(bloomday.begin(), bloomday.end());
        int ans=-1;
        if (bloomday.size()<(long long)m*k) {
            return -1;
        }
        while(low<=high) {
            int mid=(low+high)/2;
            if (canbouquet(bloomday, m, k, mid)) {
                high=mid-1;
                ans=mid;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        return binarySearch(bloomDay, m, k);
    }
};