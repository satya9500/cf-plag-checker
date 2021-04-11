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
     string s; cin >> s;
     int op = 0;
     int len = s.length();
     for(int i = 0; i < len; i++) {
      if(i < len - 1 && s[i] != '*' && s[i + 1] != '*' && s[i] == s[i + 1]) {
       op++;
       s[i + 1] = '*';
      }
      if(i < len - 2 && s[i] != '*' && s[i + 2] != '*' && s[i] == s[i + 2]) {
       op++;
       s[i + 2] = '*';
      }
     }
     cout << op << '\n';
    }
 return 0;
}
                        