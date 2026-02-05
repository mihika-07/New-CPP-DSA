#include<iostream>
#include<vector>
using namespace std;

class Solution {
  private:
  int ntimes(int mid, int n, int m) {
    long long ans=1;
    for (int i=1; i<=n; i++) {
      ans=ans*mid;
      if (ans>m) {
        return 2;
      }
    }
    if (ans==m) {
      return 1;
    }
    return 0;
  }

  int binarySearch(int n, int m) {
    int low=1;
    int high=m;
    while (low<=high) {
      int mid=(low+high)/2;
      int midN=ntimes(mid, n, m);
      if (midN==1) {
        return mid;
      }
      else if (midN==0) {
        low=mid+1;
      }
      else {
        high=mid-1;
      }
    }
    return -1;
  }
public:
  int NthRoot(int N, int M) {
       return binarySearch(N, M);
    }
};
