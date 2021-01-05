//////////////////////////// ****   JAI SHREE RAM   **** //////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define double long double
void fun(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); 
   #endif
}
int __gcd(int a, int b) {if(b==0) return a; return __gcd(b, a%b);}
int poww(int a, int b, int md) {if(b<0) return 0; if(a==0) return 0; int res=1;
    while(b) {if(b&1){res=(1ll*res*a)%md;}a=(1ll*a*a)%md;b>>=1;}return res;}
int divide(int a, int b, int md) {int rr=a*(poww(b, md-2, md));rr%=md;return rr;}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
const int size = 1e5 + 5;
//////////////////////////////////////////////////////////////////////////////////
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); fun();
    int t; cin >> t;
    while(t--) {
     int n, u, v; 
     cin >> n;
     int w[n + 1], degree[n + 1], ans[n + 1];
     memset(degree, 0, sizeof(degree));
     for(int i = 1; i <= n; i++) {
      cin >> w[i];
     }
     for(int i = 1; i < n; i++) {
      cin >> u >> v;
      degree[u]++;
      degree[v]++;
     }
     int curr = 0;
     priority_queue<int> pq;
     for(int i = 1; i <= n; i++) {
      curr += degree[i] * w[i];
      for(int j = 1; j < degree[i]; j++) {
       pq.push(-w[i]);
      }
     }
     for(int i = n - 1; i > 0; i--) {
      ans[i] = curr;
      if(!pq.empty()) {
       curr -= -pq.top();
       pq.pop();
      }
     }
     for(int i = 1; i < n; i++) {
      cout << ans[i] << ' ';
     }
     cout << '\n';
    }
 return 0;
}
                        