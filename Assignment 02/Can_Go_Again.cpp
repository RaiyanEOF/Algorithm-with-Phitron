#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int A,B;
    long long int W;
    Edge(int A,int B,long long int W){
        this->A = A;
        this->B = B;
        this->W = W;
    }
};
long long dis[1005];
vector<Edge> edge_list;
long long int N, E;
bool cycle = false;
void bellman_ford(int S){
    for(int i=0; i<=N;i++){
        dis[i] = LLONG_MAX;  
    }
    dis[S] = 0;  
    for(int i=0;i<N-1;i++){
        for(auto ed : edge_list){
            if (dis[ed.A] != LLONG_MAX && dis[ed.A] + ed.W < dis[ed.B]){
                dis[ed.B] = dis[ed.A] + ed.W;
            }
        }
    }
    for(auto ed : edge_list){
        if(dis[ed.A] != LLONG_MAX && dis[ed.A] + ed.W < dis[ed.B]){
            cycle = true;
            return;
        }
    }
}
int main(){
    cin >> N >> E;
    while (E--){
        int A,B;
        long long int W;
        cin >> A >> B >> W;
        edge_list.push_back(Edge(A, B, W));
    }
    int S;
    cin >> S;
    bellman_ford(S);
    if(cycle){
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    int T;
    cin >> T;
    while (T--){
        int D;
        cin >> D;
        if(dis[D] == LLONG_MAX){
            cout << "Not Possible" << endl;
        } 
        else{
            cout << dis[D] << endl;
        }
    }
    return 0;
}
