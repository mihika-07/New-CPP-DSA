# include<iostream>
# include<vector>
# include<map>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
       map<long long, int> presummap;
       long long sum=0;
       int maxlen=0;
       for (int i=0; i<nums.size(); i++) {
        sum=sum+nums[i];
        if (sum==k) {
            maxlen = max(maxlen, i+1);
        }
        long long rem=sum-k;
        if (presummap.find(rem)!= presummap.end()) {
            int len= i-presummap[rem];
            maxlen=max(maxlen,len);
        }
        if (presummap.find(sum)== presummap.end()) {
            presummap[sum]=i;
        }
       } 
       return maxlen;
    }
};
