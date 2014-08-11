// Longest Consecutive Sequence 
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int count = 1;
        unordered_map<int, bool> table;
        for(auto it = num.begin(); it != num.end(); it++) {
            table[*it] = true;
        }
        
        for(auto i=num.begin(); i!=num.end(); i++) {
            int temp = *i;
            int ct = 1;
            table.erase(temp); 
            while(table.count(temp+1)) {ct++; temp++; table.erase(temp); }
            temp = *i;
            while(table.count(temp-1)) {ct++; temp--; table.erase(temp); }
            if(count < ct) {
                count = ct;
            }
        }
        
        return count;
    }
};
