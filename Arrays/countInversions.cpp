#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    int merge(vector<int> & arr, int left, int mid, int right) {
        int count=0;
        int n= arr.size();
        int n1= mid-left+1;
        int n2= right-mid;
        vector<int> l(n1);
        vector<int> r(n2);
        for (int i = 0; i < n1; i++) {
            l[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            r[j] = arr[mid + 1 + j];
        }
        int i=0;
        int j=0;
        int k=left;
        while (i<n1 && j<n2) {
            if (l[i]<= r[j]) {
                arr[k]=l[i];
                i++;
            }
            else {
                count=count+ n1 -i;
                arr[k]=r[j];
                j++;
            }
            k++;
        }
        while(i<n1) {
            arr[k]=l[i];
            i++;
        }
        while(j<n2) {
            arr[k]=r[j];
            j++;
        }
        return count;
    }
    int mergeSort(vector<int> & arr, int left, int right) {
        int count=0;
        if (left>=right) {
            return count;
        }
        int mid= (right-left)/2 + left;
        count+=mergeSort(arr, left, mid);
        count+=mergeSort(arr, mid+1, right);
        count+=merge(arr, left, mid, right);
        return count;
    }
public:
    int numberOfInversions(vector<int> nums) {
        int n=nums.size();
        return mergeSort(nums, 0, n-1);
    }
};