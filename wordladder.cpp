// Word Ladder
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    // main idea: double breadth first search
    // take the advantage of set that look up an element cost O(1), find 
    vector<string> findDict(string str, unordered_set<string> &dict) {
        vector<string> res;
        int m = str.size();
        string s;
        for(int i=0; i<m; i++) {
            s = str;
            for(char j = 'a'; j<='z'; j++) {     // if change on char in str
                s[i] = j;
                if((s!=str) && (dict.find(s)!=dict.end())) {   // if the new str can be find in dict
                    res.push_back(s);            // push to the current level
                }
            }
        }
        return res;
    } 
    
    bool valid(string s1, string s2) {
        bool flag = false;    // mark if there is one and only one char that is not the same
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(flag==true) {   // there is already one char not the same
                    return false;  // cause Only one letter can be changed at a time
                }
                else { flag = true;}  // find the first one char that is not the same
            }
        }
        // since there are no two strings all the same, (s1[i] != s2[i]) will happen for sure
        return true;      // so if there is no more than one different char, it's valid.
    }
    

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(valid(start, end)) { return 2; }
        
        struct node{
            string str;
            int lev;
            node(string s, int l):str(s), lev(l) {}
        };
        
        queue<node> q, rq;           // build two trees
        map<string, bool> mark, rmark;
        int level=1, rlevel=1;
        q.push(node(start, level));
        rq.push(node(end, rlevel));
        for(auto it = dict.begin(); it != dict.end(); it++) {
            mark[*it] = false;
            rmark[*it] = false;
        }
        
        while(!q.empty() && !rq.empty()) {
            if(q.size()<rq.size()) {
                while(!q.empty() && q.front().lev == level) {
                    vector<string> l = findDict(q.front().str, dict);   // all the valid str in dict
                    for(auto it=l.begin(); it!=l.end(); it++) {
                        if(!mark[*it]) {   // if it has not been marked
                            mark[*it] = true;
                            if(rmark[*it])  // if it has been marked in the other tree
                            { // meaning there's a connection
                                return q.front().lev + rq.back().lev;
                            }
                            else {
                                q.push(node(*it, level+1));
                            }       
                        }
                    }
                    q.pop();  // if not find a connection, keep doing breath first search, move to next node
                }
                level++;
            }
            else {
                while(!rq.empty() && rq.front().lev == rlevel) {
                    vector<string> lr = findDict(rq.front().str, dict);
                    for(auto it = lr.begin(); it != lr.end(); it++) {
                        if(!rmark[*it]) {   // if it has not been marked
                            rmark[*it] = true;
                            if(mark[*it])  // if it has been marked in the other tree
                            { // meaning there's a connection
                                return rq.front().lev + q.back().lev;
                            }
                            else {
                                rq.push(node(*it, rlevel+1));
                            }       
                        }
                    }
                    rq.pop();
                }
                rlevel++;
            }
        }
        
        return 0;
    }
};