#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int binarySearch(vector<int> &arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if (arr[mid]==target) {
                return mid;
            }
            else if (arr[mid]>=arr[low]) {
                if (arr[low]<=target && target<=arr[mid]) {
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
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        return binarySearch(nums, target);
    }
};