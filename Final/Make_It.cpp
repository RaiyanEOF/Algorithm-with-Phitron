#include<bits/stdc++.h>
using namespace std;
bool reach(int n){
    while(n>1){
        if(n%2==0){
            n /= 2;  
        } 
        else if(n>=3){
            n -= 3;  
        } 
        else{
            return false;  
        }
    }
    return n==1;  
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        cout << (reach(n) ? "YES" : "NO") << endl;
    }
    return 0;
}
