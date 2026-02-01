#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {
        int res=1;
        for (int i=0; i<c-1; i++) {
            res= res * (r-1-i);
            res= res/(i+1);
        }
        return res;
    }
};