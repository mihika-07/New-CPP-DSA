#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    void swapgreater(vector<int>& nums1, vector<int>& nums2, int m, int n) {
        if (nums1[m]> nums2[n]) {
            swap(nums1[m], nums2[n]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len= n+m;
        int gap= (len/2) + (len%2);
        while (gap>0) {
            int left=0;
            int right= left+ gap;
            while (right< len) {
                if (left<m && right>=m) {
                    swapgreater(nums1, nums2, left, right-m);
                }
                else if (left>=m) {
                    swapgreater(nums2, nums2, left-m, right-m);
                }
                else {
                    swapgreater(nums1, nums1, left, right);
                }
                left++; right++;
            }
            if (gap==1) {
                gap=0;
            }
            gap= (gap/2) + (gap%2);
        }
    }
};