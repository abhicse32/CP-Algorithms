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


vector<int> print_occurence_index(string const &text, string const &pattern){
    int t_size = text.size(), p_size = pattern.size();
    vector<int> result;
    if(t_size < p_size) return result;
    int mod = 1e9 + 9;
    int p = 53;
    vector<long long> pi_mod(t_size);
    pi_mod[0] = 1;
    for(int i=1;i<t_size;++i)
        pi_mod[i] = (pi_mod[i-1]* p) % mod;
    
    vector<long long> text_hash(t_size+1, 0);
    for(int i=0;i<t_size; ++i)
       text_hash[i+1] = (text_hash[i] + (text[i] - 'a' + 1) * pi_mod[i] ) % mod;

    long long p_hash = 0;
    for(int i=0;i < p_size ; ++i)
        p_hash = (p_hash + (pattern[i]- 'a' + 1) * pi_mod[i] ) % mod;

    for(int i=0;i + p_size - 1 < t_size; ++i){
        long long sub_hash = (text_hash[i + p_size] - text_hash[i] + mod) % mod;
        if(sub_hash == (p_hash * pi_mod[i]) % mod) 
            result.push_back(i);
    }
    return result;
}

int main(){
    string pattern, text;
    cin >> text >> pattern;
    vector<int> result =  print_occurence_index(text, pattern); 
    for(auto v: result) cout << v <<" ";
    cout <<endl;
}
