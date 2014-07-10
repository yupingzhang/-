// 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// 
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},
// 
//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)
//     
// //Complexity:  O(n^3)    
// //output are unique pairs. 
// //So sorted the vector, check the element see if it's the same as the previous one. (Not for the first run.)
// //there's a  O(n^2) method:
// 
// Two iterations:
// 1. 1st pointer from 1 to index end-2
// 2. while (2nd<3rd)
// Condition: 
// 1. if (array[1st]+array[2nd]+array[3rd]==0), get one result
// 2. if (array[1st]+array[2nd]+array[3rd]>0), 3rd -1
// 3. if (array[1st]+array[2nd]+array[3rd]<0), 2nd +1 

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // similar to N Qweens problem
        // choose a, b, check the qualified c
        vector<vector<int> > result;
        int len = num.size();
        if(len<3)
            return result;
        int a, b, c;
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            if(i != 0 && num[i] == num[i-1]) {continue; }
            a = num[i];
            for(int j=i+1; j<len-1; j++) {
                if(j != i+1 && num[j] == num[j-1]) {continue; }
                b = num[j];
                for(int k=j+1; k<len; k++) {
                    if(k != j+1 && num[k] == num[k-1]) {continue; }
                    c = num[k];
                    if(a+b+c == 0) {
                        int t[] = {a, b, c};
                        vector<int> temp(t, t+3);
                        result.push_back(temp);
                        break;
                    }
                }
            }
        }
        return result;
        
    }
};