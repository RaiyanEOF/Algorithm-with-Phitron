#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>> grid;
vector<pair<int,int>> d = {{0,1},{1,0},{0,-1},{0,1}};
bool vis[1005][1005];
bool isValid(int i, int k, vector<vector<char>>& grid){
    return i >= 0 && i < n && k >= 0 && k < m && grid[i][k] == '.';
}
bool dfs(int si,int sk, int Di, int Dk, vector<vector<char>>& grid){
    if(si == Di && sk == Dk)
        return true;  
    vis[si][sk] = true;
    for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int ck = sk + d[i].second;
        if(isValid(ci,ck,grid) && !vis[ci][ck]){
            if(dfs(ci,ck,Di,Dk,grid))  
                return true;
        }
    }
    return false;  
}
int main(){
    cin >> n >> m;
    grid.resize(n, vector<char>(m)); 
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++)
            cin >> grid[i][k];   
    }
    int si,sk,di,dk;
    cin >> si >> sk >> di >> dk;
    memset(vis,false,sizeof(vis));
    if(dfs(si,sk,di,dk,grid))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl; 

    return 0;
}
