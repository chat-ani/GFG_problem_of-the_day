//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//writter Anirban

// } Driver Code Ends
// User function Template for C++

class Solution {
    bool check(int x, int y, int n_x, int n_y, int N, int M, vector<vector<char>>& grid, vector<vector<int>>& dis){
        return (n_x >= 0 && n_x < N && n_y >= 0 && n_y < M && grid[n_x][n_y] != 'X' && dis[n_x][n_y] > dis[x][y] + 1);
  }
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        vector<vector<int>> dis(N, vector<int> (M, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 'X'){
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        int res = INT_MAX;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int i = 0; i < 4; i++){
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if(check(x, y, n_x, n_y, N, M, grid, dis)){
                    dis[n_x][n_y] = dis[x][y] + 1;
                    q.push({n_x, n_y});
                    if(grid[n_x][n_y] == 'Y')
                        res = min(res, dis[n_x][n_y]);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends