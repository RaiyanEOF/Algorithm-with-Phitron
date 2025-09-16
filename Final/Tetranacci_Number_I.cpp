#include<bits/stdc++.h>
using namespace std;      
long long int dp[1005];
long long int tetranacci(long long int n)
{
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(n == 3) return 2;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = tetranacci(n-1) + tetranacci(n-2) + tetranacci(n-3) + tetranacci(n-4);  
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    long long int n;
    cin >> n;
    cout << tetranacci(n) << endl;
    return 0;
}
