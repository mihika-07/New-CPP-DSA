#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int binarySearch(vector<int> &arr, int low, int high, int target) {
        if (low>high) {
            return -1;
        }
        int mid= (high+low)/2;
        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid]>target) {
            return binarySearch(arr, low, mid-1, target);
        }
        return binarySearch(arr, mid+1, high, target);
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, (nums.size()-1), target);
    }
};