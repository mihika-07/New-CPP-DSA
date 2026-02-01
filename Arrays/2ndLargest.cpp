#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest=nums[0];
        int slargest=-1;
        for (auto it=nums.begin(); it!=nums.end(); it++) {
            if (largest<*it) {
                slargest=largest;
                largest=*it;
            }
            else if (*it<largest && *it>slargest) {
                slargest=*it;
            }
        }
        return slargest;
    }
};