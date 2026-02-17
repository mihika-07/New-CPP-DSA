#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
    private:
    int students(vector<int> arr, int k, int pages) {
        int cntstudents=1;
        int n=arr.size();
        int sum=arr[0];
        for (int i=1; i<n; i++) {
            if (sum+arr[i]>pages) {
                cntstudents++;
                sum=arr[i];
            }
            else {
                sum+=arr[i];
            }
        }
        return cntstudents;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int low=*max_element(arr.begin(), arr.end());
        int high=accumulate(arr.begin(), arr.end(), 0);
        if (k>arr.size()) {
            return -1;
        }
        int ans=-1;
        while(low<=high) {
            int mid=(high+low)/2;
            int countstudents=students(arr, k, mid);
            if (countstudents<=k) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};