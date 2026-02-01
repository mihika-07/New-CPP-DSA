#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt1=0;
        int cnt2=0;
        int el1=0;
        int el2=0;
        int mini= int(n/3) + 1;
        for (int i=0; i<n; i++) {
            if (cnt1==0 && nums[i]!=el2) {
                el1=nums[i];
                cnt1++;
            }
            else if (cnt2==0 && nums[i]!=el1) {
                el2=nums[i];
                cnt2++;
            }
            else if (el1==nums[i]) {
                cnt1++;
            }
            else if (el2==nums[i]) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for (int i=0; i<n; i++) {
            if (nums[i]==el1) {
                cnt1++;
            }
            else if (nums[i]==el2) {
                cnt2++;
            }
        }
        if (cnt1>= mini && cnt2>= mini) {
            if (el1>el2) {
                return {el1, el2};
            }
            else {
                return {el2, el1};
            }
        }
        else if (cnt2<mini && cnt1>=mini) {
            return {el1};
        }
        else if (cnt1<mini && cnt2>=mini) {
            return {el2};
        }
        else {
            return {};
        }
    }
};