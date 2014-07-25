// Remove Element 
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
// Pay attention to the corner case!!!
// E.g. [3,3] 3

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // move the elements(!=elem) from the end to fill the slots
        if(n == 0) return 0;
        int end = n-1;
        for(int i=0; i<=end; i++) {
            if(A[i] == elem) {
                if(i == end) { end--; }               // if already reach the end, length -1
                else{
                    while((A[end] == elem) && (i < end)) { end--; }  // find an element(!=elem) from the end
                    if(i == end) { end--; } 
                    else {
                        A[i] = A[end];                    // fill the slot
                        end--;
                    }
                }
            }
        }
        return end+1;
    }
};
