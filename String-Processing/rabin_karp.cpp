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

// returns the index of occurrence of a pattern in a string


vi get_occurences(string& txt, string& pattern){
    int txt_size = txt.size(), pat_size = pattern.size();
    vi occurence_indices;
    if(txt_size >= pat_size){ 
        vector<ll> prime_powers(txt_size, 0);
        prime_powers[0] = 1;
        ll m = 131;
        for(int i=1;i < txt_size; ++i) 
            prime_powers[i] = (prime_powers[i-1] * m) % p;
        // computes txt hashes
        vector<ll> txt_hashes(txt_size + 1, 0);
        for(int i=0;i < txt_size; ++i)  
            txt_hashes[i + 1] = (txt_hashes[i] + prime_powers[i] * txt[i]) % p;
        ll pattern_hash = 0;
        for(int i = 0; i < pat_size; ++i)
            pattern_hash = (pattern_hash + prime_powers[i] * pattern[i]) % p;
        
        for(int i=0;i <= txt_size - pat_size; ++i){
           ll curr_hash = (txt_hashes[i + pat_size] - txt_hashes[i] + p) % p;
           if(curr_hash == pattern_hash * prime_powers[i] % p)
               occurence_indices.push_back(i);
        }
    }
    return occurence_indices;   
}

int main(){
    string txt = "pattern inside a text is pattern";
    string pattern = "pattern";
    vi occr_indices = get_occurences(txt, pattern);
    for(auto v: occr_indices) cout << v <<" ";
    cout << endl;
}
