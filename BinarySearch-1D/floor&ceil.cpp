#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        int floor(vector<int> &arr, int target) {
            int n= arr.size();
            int low=0;
            int high=n-1;
            int floor=-1;
            while(low<=high) {
                int mid=(low+high)/2;
                if (arr[mid]<=target) {
                    floor=arr[mid];
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            return floor;
        }
        int ceil(vector<int> &arr, int target) {
            int n=arr.size();
            int low=0;
            int high=n-1;
            int ceil=-1;
            while(low<=high) {
                int mid=(high+low)/2;
                if (arr[mid]>=target) {
                    ceil=arr[mid];
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            return ceil;
        }
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        vector<int> ans;
        ans.push_back(floor(nums, x));
        ans.push_back(ceil(nums,x));
        return ans;
    }
};