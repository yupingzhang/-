// Text Justification
// 
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// 
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// 
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// 
// For the last line of text, it should be left justified and no extra space is inserted between words.
// 
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// 
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
// 
// click to show corner cases.

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if( words.size() == 0) {
            return words;
        }
        if( words.size() == 1 ) {
            if(words[0].size() < L) {
                words[0] += string(L-words[0].size(), ' ');
            }
            return words;
        }
        //go through the vector
        //put as many words as possible in one line, then adjust the space
        //no extra space with last line
        
        string str = "";
        int numWords = words.size();
        int i=0, len=0, count=0, totalcount=0, extra=0, diff=0, ea=0, line=0;
        for(i=0; i<numWords; i++) {
            if(str.length() + words[i].length() <= L) {
                str += words[i]+" ";
                count++;
            }
            else {  
                //format one line, edit &words vector and adjust the space
                str.pop_back();
                len = str.length();
                extra = L - len; 
                if(extra == 0) {
                    words[line] = str;
                }
                else {
                    if(count == 1) { 
                        if(line != totalcount) { words[line] = words[totalcount]; }
                        words[line] += string(extra, ' ');
                    }
                    else {  
                    //Extra spaces between words should be distributed as evenly as possible.
                        ea = int(extra/(count-1));
                        diff = extra - ea*(count-1);   // this diff will distribute from left 1 by 1
                        if(line != totalcount) 
                            words[line] = "";
                        for(int j=totalcount; j<totalcount+count-1; j++) {
                            if(line != j) {words[line] += words[j]; }
                             
                            if(diff != 0) {
                                words[line] += string(ea+1+1, ' ');
                                diff--;
                            }
                            else {
                                words[line] += string(ea+1, ' ');
                            }
                        }
                        //add the last one
                        words[line] += words[totalcount+count-1]; 
                    }
                }
                //set temp variables back to init
                str = "";
                totalcount += count;
                count = 0;
                line++;
                i--;
            }
        }
        //take care of the last line and erase the extra content
        if(count > 0) {
            str.pop_back();
            len = str.length();
            extra = L - len; 
            words[line] = str + string(extra, ' ');
        }
        
        if(line < numWords-1) {
            for(int k=0; k<numWords-line-1; k++) {
                words.pop_back();
            }
        }
  
        return words;
    }
};