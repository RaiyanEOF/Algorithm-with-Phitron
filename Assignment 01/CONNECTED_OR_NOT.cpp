#include <bits/stdc++.h>
using namespace std;
bool adj_matrix[1005][1005];  
int main(){
    int N,E;
    cin>> N >> E;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            adj_matrix[i][j] = false;
        }
    }
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adj_matrix[A][B] = true;  
    }
    int Q;
    cin >> Q;
    while (Q--){
        int A, B;
        cin >> A >> B;
        if(adj_matrix[A][B] || A==B){
            cout << "YES\n";
        } 
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
