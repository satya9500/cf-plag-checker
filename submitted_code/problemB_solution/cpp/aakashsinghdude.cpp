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
         int n;
      cin >> n;
      int x[n];
      for(int i = 0;i <n ;i++)
      {
         cin >> x[i];
      }
      set<int> s;
      sort(x, x+n);
      for(int i = n-1;i >= 0;i--)
      {
         if(s.find(x[i] + 1) == s.end())
            s.insert(x[i] + 1);
         else
         {
            if(s.find(x[i]) == s.end())
            s.insert(x[i]);
         }
               }
       cout << s.size() << endl;
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