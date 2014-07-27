/* Count and Say 
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

// traverse from left to right
// compare if the current element is the same as previous one, count
// combine result to a string

class Solution {
public:
    string repeat(string str) {
        string res = "";    //for each pair, count + value
        int previous, current, count = 1;
        char first = *str.begin();
        previous = first - '0'; 
        if(str.length() == 1) {
            res += to_string(count) + to_string(previous);
            return res;
        }
        for(string::iterator it = str.begin()+1; it != str.end(); it++) {
            current = *it - '0';
            if(current == previous) { count++; }
            else {
                res += to_string(count) + to_string(previous);
                previous = current;
                count = 1;
            }
        }
        res += to_string(count) + to_string(previous);
        return res;
    }

    string countAndSay(int n) {
        string result = "1";     //init
        if(n == 1) return result;
        for(int i=1; i<n; i++) {
            result = repeat(result);
        }
        return result;
    }
};
