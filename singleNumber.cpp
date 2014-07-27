// Single Number 

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// Magic XOR: 
// A bitwise XOR takes two bit patterns of equal length and performs the logical exclusive OR operation 
// on each pair of corresponding bits. The result in each position is 1 if only the first bit is 1 or 
// only the second bit is 1, but will be 0 if both are 0 or both are 1. 
// ((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5.

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result;
        for(int i=0; i<n; i++) {
            result ^= A[i];
        }
        return result;
    }
};
