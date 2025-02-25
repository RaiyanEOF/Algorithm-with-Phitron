#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<string> grid;
vector<vector<bool>> vis;
int dx[] = {-1, 1, 0, 0};  
int dy[] = {0, 0, -1, 1};  
bool isValid(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && grid[x][y] == '.' && !vis[x][y];
}
void dfs(int x, int y){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(isValid(newX, newY)){
            dfs(newX, newY);
        }
    }
}
int main(){
    cin >> N >> M;
    grid.resize(N);
    vis.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++){
        cin >> grid[i];
    }
    int Count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                dfs(i, j);
                Count++;
            }
        }
    }
    cout << Count << endl;
    return 0;
}
