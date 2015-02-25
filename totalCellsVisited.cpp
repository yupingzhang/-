#include <iostream>
#include <sstream>
using namespace std;

int totalCellsVisited(int n, int m) {
    int res = 1;
    int i=0, j=0;
    int dir = 1;  // direction: right, down, left, up, 1,2,3,0
    
    int **grid = new int* [n];
    for (int i = 0; i < n; i++)
        grid[i] = new int[m]();
    
    grid[0][0] = 1;
    int count = 0;
    while(true) {
//        cout << i << "  " << j << "\n";
        switch(dir) {
            case 2:
                if(i+1<n && (grid[i+1][j] == 0)) {
                    i += 1;
                    res++;
                    count = 0;
                }else {
                    count++;
                }        
                break;
            case 1:
                if(j+1<m && (grid[i][j+1] == 0)) {
                    j += 1;
                    res++;
                    count = 0;
                }else {
                    count++;
                }    
                break;
            case 0:
                if(i-1>=0 && (grid[i-1][j] == 0)) {
                    i -= 1;
                    res++;
                    count = 0;
                }else {
                    count++;
                }    
                break;
            case 3:
                if(j-1>=0 && (grid[i][j-1] == 0)) {
                    j -= 1;
                    res++;
                    count = 0;
                }else {
                    count++;
                }    
                break;
        }
        
        grid[i][j] = 1;
        dir = (dir+1)%4;
        
        if(count == 4) {
            break;
        }
    }
    
    return res;
}

int main() {
	int res;
	int n;
	int m;
    cin >> n;
    cin >> m;
	res = totalCellsVisited(n, m);
	cout << res << endl; 
	return 0;
}
