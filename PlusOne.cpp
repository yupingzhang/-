//Plus One
//Given a non-negative number represented as an array of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.

// 

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry_over;
        for(vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++ ) {
            if(*it < 9) {
                *it += 1;
                carry_over = false;
                break;
            }else {
                *it = 0;
                carry_over = true;
            }
        }
        if(carry_over == true) {
            digits.insert(digits.begin(), 1);    // add one more digit in the front
        }
        return digits;
    }
};
