#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int binarySearch(vector<int> & arr) {
        int n= arr.size();
        int ans=INT_MAX;
        int low=0;
        int high=n-1;
        int index=-1;
        while (low<=high) {
            int mid=(low+high)/2;
            if (arr[mid]>=arr[low]) {
                if (ans>arr[low]) {
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;
            }
            else {
                if (ans>arr[mid]) {
                    ans=arr[mid];
                    index=mid;
                }
                high=mid-1;
            }
        }
        return index;
    }
public:
    int findKRotation(vector<int> &nums)  {
        int n= nums.size();
        return binarySearch(nums);
    }
};