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
#define p 1000000007

ll get_hash(string& str){
   ll hash = 0, prime_pow = 1;            // assuming that the size of the alphabet is 128, we choose the prime 131 to raise the power of
   int n = str.size(), m = 131;
   for(int i=0;i < n; ++i){
       hash = (hash + str[i] * prime_pow) % p;
       prime_pow = (prime_pow * m) % p;
   }
   return hash;
}

int count_unique_substrings(string& str){
    ll hash = 0, prime_pow = 1, m = 131;
    int n = str.size();
    vector<ll> prime_powers(n, 0);
    vector<ll> str_hashes(n+1, 0);
    prime_powers[0] = 1;
    for(int i=1; i< n; ++i) prime_powers[i] = ( prime_powers[i-1] * m ) % p;
    // first compute the string hash
    for(int i=0; i< n;++i)
        str_hashes[i+1] = (str_hashes[i] + str[i] * prime_powers[i]) % p;

    int count = 0;
    // we try to find out the unique substrings of each size
    for(int l=1; l<=n; ++l){
        set<ll> unique_hashes;
        for(int i=0; i <= n - l; ++i){
            ll sub_str_hash = (str_hashes[i+l] - str_hashes[i] + p) % p;
            sub_str_hash = (sub_str_hash * prime_powers[n-i-1]) % p;
            unique_hashes.insert(sub_str_hash);
        }
        count += unique_hashes.size();
    }
    return count;
}

int main(){
    string str = "aaaaa";
   cout << count_unique_substrings(str) <<endl;
}
