#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    bool canfinish(vector<int> &bananas, int hourly, int h) {
        long long total_hours=0;
        for (int i=0; i<bananas.size(); i++) {
            total_hours+=ceil((double)bananas[i]/(double)hourly);
        }
        return total_hours<=h;
    }

    int binarySearch(vector<int> &arr, int h) {
        int n= arr.size();
        int low=1;
        int high=*max_element(arr.begin(), arr.end());
        while (low<=high) {
            int mid=(low+high)/2;
            if (canfinish(arr, mid, h)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return binarySearch(piles, h);
    }
};