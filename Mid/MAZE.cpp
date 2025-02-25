#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char maze[1005][1005];
pair<int, int> parent[1005][1005]; 
bool vis[1005][1005]; 
int N, M; 
void bfs(int Si,int Sj,int Di,int Dj){
    queue<pair<int, int>> q;
    q.push({Si,Sj});
    vis[Si][Sj] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x==Di && y==Dj){
            break;
        } 
        for (int i=0;i<4;i++){
            int nx = x + d[i].first, ny = y + d[i].second;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] && maze[nx][ny] != '#'){
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    if (!vis[Di][Dj]){
        return;
    }
    int cx = Di, cy = Dj;
    while(!(cx==Si && cy==Sj)){
        auto [px, py] = parent[cx][cy];
        if(maze[px][py] != 'R' && maze[px][py] != 'D')
            maze[px][py] = 'X';
        cx = px, cy = py;
    }
}
int main(){
    cin >> N >> M;
    int Si = -1, Sj = -1, Di = -1, Dj = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'R'){
                Si = i;
                Sj = j;
            }
            if(maze[i][j] == 'D'){
                Di = i;
                Dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    if(Si != -1 && Sj != -1 && Di != -1 && Dj != -1){
        bfs(Si, Sj, Di, Dj);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}
