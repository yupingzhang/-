// Pascal's Triangle

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;
        vector<int> init{1};
        result.push_back(init);
        int level = 0;
        vector<int> thislevel;
        for( ; level<numRows-1; level++ ) {
            int len = result[level].size();
            thislevel.clear();
            thislevel.push_back(1);
            for(int i=1; i<len; i++) {
                int value = result[level][i] + result[level][i-1];
                thislevel.push_back(value);
            }
            thislevel.push_back(1);
            result.push_back(thislevel);
        }
        return result;
    }
};
