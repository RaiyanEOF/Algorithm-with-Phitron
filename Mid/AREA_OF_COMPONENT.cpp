#include <bits/stdc++.h>
using namespace std;
 vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int x, int y, int N, int M, vector<vector<char>>& grid, vector<vector<bool>>& vis){
    return x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '.' && !vis[x][y];
}
int bfs(int x, int y, int N, int M, vector<vector<char>>& grid, vector<vector<bool>>& vis){
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    int area = 0;   
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();
        area++;       
        for(int i = 0; i < 4; i++){
            int nx = cx + d[i].first;
            int ny = cy + d[i].second;
            if(isValid(nx, ny, N, M, grid, vis)){
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return area;
}
int findMinComponentArea(int N, int M, vector<vector<char>>& grid){
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    int minArea = INT_MAX;
    bool hasComponent = false;  
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (grid[i][j] == '.' && !vis[i][j]){
                hasComponent = true;
                minArea = min(minArea, bfs(i, j, N, M, grid, vis));
            }
        }
    }
    return hasComponent ? minArea : -1;
}
int main(){
    int N, M;
    cin >> N >> M;  
    vector<vector<char>> grid(N, vector<char>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }   
    cout << findMinComponentArea(N, M, grid) << endl;
    return 0;
}
