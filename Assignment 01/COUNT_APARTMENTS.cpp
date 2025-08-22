#include <bits/stdc++.h>
using namespace std;
int N, M;
char grid[1005][1005];
bool vis [1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};  
bool isValid(int i, int j){
    return i>=0 && i<N && j>=0 && j<M && grid[i][j] == '.' && !vis[i][j];
}
void dfs(int si, int sj){
    vis[si][sj] = true;
    for(int i = 0; i < 4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(isValid(ci, cj)){
            dfs(ci,cj);
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
    }
    memset(vis,false,sizeof(false));
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
