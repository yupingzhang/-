// Search in Rotated Sorted Array II 

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j) {
            int m=(i+j)/2;
            if(A[m] == target) return true;
            if(A[i] < A[m]) {   //ascend
                if(A[i]<= target && target <= A[m]) {
                    j = m-1;
                }else {
                    i = m+1;
                }
            }
            else if(A[i] > A[m]){
                if(A[m] < target && target<= A[j] ) {
                    i = m+1;
                }else {
                    j = m-1;
                }
            }
            else{
                i++;
            }
        }
        return false;
    }
};
