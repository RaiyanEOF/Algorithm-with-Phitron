#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<char>> grid;
vector<vector<bool>> vis;
bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M && grid[i][j] == '.' && !vis[i][j];
}
int dfs(int si, int sk){
    vis[si][sk] = true;
    int area = 1;  
    for (int t=0;t<4;t++){
        int ci = si + d[t].first;
        int ck = sk + d[t].second;
        if(isValid(ci, ck)){
            area += dfs(ci, ck);
        }
    }
    return area;
}
int findMinComponentArea(){
    int minArea = INT_MAX;
    bool hasComponent = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                hasComponent = true;
                int area = dfs(i,j);
                minArea = min(minArea,area);
            }
        }
    }
    if(hasComponent){
        return minArea;
    } else {
        return -1;
    }
}
int main() {
    cin >> N >> M;
    grid.resize(N, vector<char>(M));
    vis.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    cout << findMinComponentArea() << endl;
    return 0;
}
