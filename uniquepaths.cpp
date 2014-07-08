// Unique Paths 
// 
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// 
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// 
// How many possible unique paths are there?
// 
// 
// Above is a 3 x 7 grid. How many possible unique paths are there?
// 
// Note: m and n will be at most 100.

class Solution {
public:
    vector<vector<int> > A;
    
    int uniquePaths(int m, int n) {
        // set the value for the boundaries then compute iteratively 
        vector<int> line;
        for(int i=0; i<m; i++) {
            line.push_back(1);
        }
        A.push_back(line);
        for(int j=1; j<n; j++) {
            line.clear();
            line.push_back(1);
            for(int i=1; i<m; i++) {
                int left = line.back();
                int up = A[j-1][i];
                line.push_back(left+up);
            }
            A.push_back(line);
        }

        return line.back();
    }
};