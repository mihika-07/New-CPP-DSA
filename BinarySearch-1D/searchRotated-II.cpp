#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool binarySearch(vector<int> &arr, int target) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        while(low<=high) {
            int mid= (low+high)/2;
            if (arr[mid]==target) {
                return true;
            }
            if (arr[low]==arr[mid] && arr[mid]==arr[high]) {
                high=high-1;
                low=low+1;
                continue;
            }
            if (arr[mid]>=arr[low]) {
                if (arr[low]<=target && arr[mid]>=target) {
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            else {
                if (arr[mid]<=target && arr[high]>=target) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        return binarySearch(nums, target);
    }
};