#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
    private:
    bool possible(vector<int>& weights, int days, int mid) {
        int current_weight=weights[0];
        int count=1;
        for (int i=1; i<weights.size(); i++) {
            if(current_weight+weights[i]<=mid){
                current_weight+=weights[i];
            }
            else {
                current_weight=weights[i];
                count++;
            }
        }
        return count<=days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high) {
            int mid=(low+high)/2;
            if (possible(weights, days, mid)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};