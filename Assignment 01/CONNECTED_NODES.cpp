#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj_list(N); 
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int X;
        cin >> X;
        vector<int> connected = adj_list[X];
        if(connected.empty()){
            cout << "-1" << endl; 
        } 
        else{
            sort(connected.rbegin(), connected.rend());
            for (int node : connected) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
