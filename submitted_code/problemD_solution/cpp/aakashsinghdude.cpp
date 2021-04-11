#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}
 void fun()
 {
  #ifndef ONLINE_JUDGE 
     freopen("input.txt", "r", stdin); 
     //freopen("error.txt", "w", stderr); 
     freopen("output.txt", "w", stdout); 
   #endif 
 }
void solve(){
        int n;
     cin >> n;
     int w[n+1];
     int sum =0;
     for(int i = 1;i <= n;i++)
     {
       cin >> w[i];
       sum += w[i];
     }  
          set<int> v[n+1];
     for(int i = 0;i < n-1;i++)
     {
        int x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
            }
      priority_queue<pair<int,int>> ss;
     for(int i = 1;i <= n;i++)
     {
      //cout << i << w[i] << endl;
      if(v[i].size() > 1)
        ss.push({w[i], i});
     }
          cout << sum << " ";
      while(!ss.empty())
        {
            pair<int,int> x = (ss.top());
            //cout << x.second << endl;
            if(v[x.second].size() > 0)
            {
               int y = (*(v[x.second].begin()));
               v[x.second].erase(y);
               v[y].erase(x.second);
               break;
            }
            else
            {
               ss.pop();
            }
                    }
          for(int i = 2;i < n;i++)
     {
         int mx = 0;
        while(!ss.empty())
        {
             pair<int,int> x = (ss.top());
           // cout << x.second << endl;
            if(v[x.second].size() > 0)
            {
               mx = x.first;
               int y = (*(v[x.second].begin()));
               v[x.second].erase(v[x.second].begin());
               v[y].erase(x.second);
               break;
            }
            else
            {
               ss.pop();
            }
                    }
         sum += mx;
        cout << sum << " ";
     }
      cout << endl;
 }   
signed main(){
 fun();
    fast;
    int t = 1;
    cin >> t;
    while(t--){
     solve();
    }
    return 0;
}