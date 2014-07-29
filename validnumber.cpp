// Valid Number
/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
*/

// This is the most clear and efficient solution I found!!
class Solution {
public:
    bool isNumber(const char *s) {
             if (s == NULL || s[0] == '\0') return false;
        bool cansign = true;
        bool cane = false;
        bool havee = false;
        bool candot = true;
        bool onlyspace = false;
        bool havenum = false;
        bool numbegin = false;
        while(*s != '\0') {
            char c = *(s++);
            if (c == ' '){
                if (numbegin)
                    onlyspace = true;
                continue;//skip space
            } else if (onlyspace) {     // if there's something else behind the only space, false
                return false;
            }
            if (c == '+' || c == '-') {      // can only has one sign before number begins
                if(!cansign) return false;
                cansign = false;
                numbegin = true;
                continue;
            }
            if (c == 'e') {
                if(!cane) return false;     // can not start with e or has the second e
                cane = false;
                havenum = false;
                numbegin = true;
                cansign = true;
                havee = true;
                candot = false;
                continue;
            }
            if (c == '.') { 
                if(!candot) return false;  // cannot start with dot or has a second dot 
                candot = false; 
                numbegin = true;
                cansign = false;
                continue;
            }
            if (c >= '0' && c <= '9') {
                havenum = true;
                numbegin = true;
                cansign = false;
                if(!havee) cane = true;
            } else {
                return false;
            }
        }
        return havenum;
        
    }
};
