//Sudoku Solver 

class Solution {
public:
     
    bool isValid(vector<vector<char> > &board, int i, int j)
    {
         for(int k=0;k<9;k++)  
         {  
            if(k!=j && board[i][k] == board[i][j])   // same row
                return false;
         }
         for(int k=0;k<9;k++)  
         {  
             if(k!=i && board[k][j] ==board[i][j])   // same line
                return false;
         }
    
         for(int row = i/3*3; row<i/3*3+3; row++)    // same small box
         {  
             for(int col=j/3*3; col<j/3*3+3; col++)  
             {  
                 if(row ==i && col==j)
                    continue;
                 if(board[row][col]==board[i][j])  
                     return false;  
             }  
         }
        return true;
    }
    
    bool sudoku(vector<vector<char> > &board, int i, int j)
    {
        if(j==9) //one column til end
            return sudoku(board, i+1, 0);  //start from the first element of next row
        if(i==9)
        {
            return true;
        }
        if(board[i][j]=='.')   // place need to fill in
        {
            for(int k=1;k<=9;k++)  //enumerate 1-9
            {
                board[i][j] = (char)(k+'0');
                if(isValid(board, i, j))
                {
                    if(sudoku(board, i, j+1))
                        return true;
                }
                board[i][j] = '.';
            }
        }
        else
        {
            return sudoku(board, i, j+1);
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        sudoku(board, 0, 0);
    }
};
