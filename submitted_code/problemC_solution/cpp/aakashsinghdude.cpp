#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}
  void solve(){
         string s;
      cin >> s;
      int n = s.length();
      int i  = 0;
      int j  = 1;
      int cnt = 0;
      while(i < n)
      {
         if(i + 1 < n)
         {
            if(s[i] == s[i+1])
            {
             cnt++;
             j = i+2;
            }
         }
         if(i + 2 < n)
         {
            if(s[i] == s[i+2])
            {
            cnt++;
            j = i+3;
            }
         }
         i = j;
         j = i + 1;
      }
       cout << cnt << endl;
}   
int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
     solve();
    }
    return 0;
}