// Word Ladder II 
/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

////////////////////////
// Refer to: http://yucoding.blogspot.com/2014/01/leetcode-question-word-ladder-ii.html
// Main idea:
// Duplicates is permitted within a level. 
// Using map storing the paths
// Using two queues to store the current level words and the next level words
// compute the next level from the current level
// Attention for the memory and time complexity.

class Solution {
public:
    unordered_map<string, vector<string> > map;    //for each element in the dict, store what can come before it
    vector<vector<string>> res;
    vector<string> path;

	// find all the valid string, forming the next level
    void findInDict(string str, unordered_set<string> &dict, unordered_set<string> &next_lev) {
        int m = str.size();
        string s;
        for(int i=0; i<m; i++) {
            s = str;
            for(char j='a'; j<='z'; j++) {
                s[i] = j;
                if(dict.find(s) != dict.end()) { // if can be found in dict
                    next_lev.insert(s);          // insert into next level
                    map[s].push_back(str);   // s as key, str as value (in the tree structure, s can come after str)
                }
            }
        }
    }
    
    void output(string start, string last) {
        if(last == start) {                     // a full path from end to start
            reverse(path.begin(), path.end());  // reverse the path
            res.push_back(path);                // push the path to result
            reverse(path.begin(), path.end());
        }else{
            for(int i=0; i<map[last].size(); i++) {
                path.push_back(map[last][i]);
                output(start, map[last][i]);  //recursively go find the previous one in the path
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map.clear();
        res.clear();
        path.clear();
        dict.insert(start);
        dict.insert(end);
        
        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);
        
        while(true) {
            
            for(auto it=cur_lev.begin(); it!=cur_lev.end(); it++) { //delete previous level words
            	dict.erase(*it); 
            }
            for(auto it=cur_lev.begin(); it!=cur_lev.end(); it++) { //find current level words
                findInDict(*it, dict, next_lev);
            }
            
            if(next_lev.empty()) {return res;}   // no solution, empty result
            
            if(next_lev.find(end) != dict.end()) {  // if find end string
                output(start, end);
                return res;
            }
            
            cur_lev.clear();
            cur_lev = next_lev;
            next_lev.clear();
        }
        return res;
    }
};
