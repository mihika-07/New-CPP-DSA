#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    int binaryUpper(vector<int> &arr, int target) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high) {
            int mid= (high+low)/2;
            if (arr[mid]> target) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
public:
    int upperBound(vector<int> &nums, int x){
        return binaryUpper(nums, x);
    }
};