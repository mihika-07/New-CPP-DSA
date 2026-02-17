//similar to agressive cows

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    bool possible(vector<int> position, int balls, int force) {
        int cntballs=1;
        int lastball=position[0];
        int n=position.size();
        for (int i=1; i<n; i++) {
            if (position[i]-lastball>=force) {
                cntballs++;
                lastball=position[i];
            }
            if (cntballs>=balls) {
                return true;
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low=1;
        int high=(position.back() - position[0]) / (m - 1);
        int ans=-1;
        while(low<=high) {
            int mid=(high+low)/2;
            if (possible(position, m, mid)) {
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
};