#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int insert(vector<int> &arr, int target) {
        int n=arr.size();
        int high=n-1;
        int low=0;
        int index=n;
        while(low<=high) {
            int mid=(high+low)/2;
            if (arr[mid]==target) {
                return mid;
            }
            else if (arr[mid]>target) {
                index=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return index;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return insert(nums, target);
    }
};