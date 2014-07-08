// Unique Paths II
// 
// Follow up for "Unique Paths":
// 
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// 
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
// 
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// 
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.
// 
// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      
        //traverse each line, and compute the possibility of each point
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j] == 0) {
                    if(i == 0 && j == 0) {
                        obstacleGrid[i][j] = 1;
                    }
                    else if(i == 0) {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    }
                    else if(j == 0) {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    }
                    else {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                    }
                }
                else {
                    obstacleGrid[i][j] = 0;   //obstacle
                }
            }
        }
            
        return obstacleGrid[m-1][n-1];
    }
};