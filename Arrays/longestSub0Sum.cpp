#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n= arr.size();
        map<int, int> mpp;
        int maxlen= 0;
        int sum=0;
        for (int i=0; i<n; i++) {
          sum= sum+ arr[i];
          if (sum==0) {
            maxlen= max(maxlen, i+1);
          }
          int rem= -sum;
          if (mpp.find(rem)!=mpp.end()) {
            int len= i-mpp[rem];
            maxlen=max(maxlen, len);
          }
          if (mpp.find(sum)==mpp.end()) {
            mpp[sum]=i;
          }
        }
        return maxlen;
    }
};