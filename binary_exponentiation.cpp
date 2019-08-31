#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define mii map<int, int>
#define si set<int>
#define sci(n) scanf("%d",&n)
#define sti stack<int>
#define qi queue<int>
#define pii pair<int,int>
#define ll long long

ll binpow(ll base, ll exp){
   ll res = 1;
   while(exp){
       if(exp & 1)
           res *= base;
        base *= base; 
        exp >>= 1;
   }
   return res;
}

ll binpow_mod(ll base, ll exp, ll m){
   base %= m;
   ll res = 1;
   while(exp){
       if(exp & 1 )
           res = (res * base) % m;
       base = (base * base) % m;
       exp >>= 1 ;
   } 
   return res;
}

int main(){
    cout << binpow_mod(2, 10, 17) <<endl;
    return 0;
}
