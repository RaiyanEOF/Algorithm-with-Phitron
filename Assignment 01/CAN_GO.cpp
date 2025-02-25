#include <bits/stdc++.h>
using namespace std;
int N, M;  
vector<string> grid;  
vector<vector<bool>> visited;  
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool isValid(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && grid[x][y] != '#' && !visited[x][y];
}
bool bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == endX && y == endY){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY)){
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    return false;  
}
int main(){
    cin >> N >> M;
    grid.resize(N);
    visited.resize(N, vector<bool>(M, false));
    int startX, startY, endX, endY;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'A'){
                startX = i;
                startY = j;
            } 
            else if(grid[i][j] == 'B'){
                endX = i;
                endY = j;
            }
        }
    }
    if(bfs(startX, startY, endX, endY)){
        cout << "YES" << endl;
    } 
    else{
        cout << "NO" << endl;
    }
    return 0;
}
