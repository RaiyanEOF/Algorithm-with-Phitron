#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
vector<pair<int,int>> d = {{-2, -1},{-2, 1},{2, -1},{2, 1},{-1, -2},{-1, 2},{1, -2},{1, 2}};
int KnightMoves(int N,int M,int Ki,int Kj,int Qi,int Qj){
    if (Ki==Qi && Kj==Qj){
        return 0; 
    }
    memset(vis,false,sizeof(vis));    
    queue<pair<int,int>> q;
    q.push({Ki,Kj});
    vis[Ki][Kj] = true;   
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        steps++;
        while (size--){
            auto [x, y] = q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int nx = x + d[i].first, ny = y + d[i].second;
                if(nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny]){
                    if(nx==Qi && ny==Qj){
                        return steps; 
                    }
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1; 
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, Ki, Kj, Qi, Qj;
        cin >> N >> M >> Ki >> Kj >> Qi >> Qj;
        cout << KnightMoves(N,M,Ki,Kj,Qi,Qj) << endl;
    }
    return 0;
}
