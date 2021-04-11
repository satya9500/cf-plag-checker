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
     int n; cin >> n;
     int arr[n + 1];
     for(int i = 1; i <= n; i++) {
      cin >> arr[i];
     }
     set<int> sett;
     for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
       sett.insert(arr[j] - arr[i]);
      }
     }
     cout << sett.size() << '\n';
    }
 return 0;
}
                        