#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    vector<int> range(vector<int> arr, int target) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        int start=-1;
        int end=-1;
        while (low<=high) {
            int mid=low + (high-low)/2;
            if (arr[mid]==target) {
                start=mid;
                end=mid;
                while (start>0 && arr[start-1]==target) {
                    start--;
                }
                while (end<n-1 && arr[end+1]==target) {
                    end++;
                }
                return {start,end};
            }
            else if (arr[mid]>target) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return {-1, -1};
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return range(nums, target);
    }
};