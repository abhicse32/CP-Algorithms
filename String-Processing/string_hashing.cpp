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

long long compute_hash(string const &s){
    const int m = 1e9 + 7;
    const int p = 103;   // some random prime
    long long hash_val=0, pow_pi =1;
    for(auto c: s){
        hash_val = (hash_val + (c - 'a'+ 1)*pow_pi) % m;
        pow_pi = (pow_pi* p)% m;
    }
    return hash_val;
}

int count_unique_substrings(string const &str){
    int n = str.size();
    int mod = 1e9 + 9;
    int p = 53;
    vector<long long> pi_mod(n);
    pi_mod[0] = 1;
    for(int i=1;i<n;++i)
        pi_mod[i] = (pi_mod[i-1]* p) % mod;

    vector<long long> prefix_hash(n+1, 0);
    for(int i=0; i< n; ++i)
       prefix_hash[i+1] = (prefix_hash[i] + (str[i] - 'a' + 1)* pi_mod[i]) % mod;

    int unique_count = 0;
    for(int l=1; l<= n; ++l){
        set<long long> unique_hashes;
        for(int i=0; i<=n-l; ++i){
            long long curr_hash = (prefix_hash[i+l] - prefix_hash[i] + mod) %mod;
            curr_hash = (curr_hash * pi_mod[n-i-1]) % mod;
            unique_hashes.insert(curr_hash);
        }
        unique_count += unique_hashes.size();
    }
    return unique_count;
}
int main(){
    string str;
    cin >> str;
    cout << count_unique_substrings(str) << endl;
}
