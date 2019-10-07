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

vi build_prefix(string pattern){
    int n= pattern.size();
    vi prefix_arr(n, 0);
    for(int i=1; i< n;++i){
        int j = prefix_arr[i-1];
        while(j > 0 && pattern[i] != pattern[j]) j = prefix_arr[j-1];
        if(pattern[i] == pattern[j])
            ++j;
        prefix_arr[i] = j;
    } 
    return prefix_arr;
}

vi find_matches(string const &txt, string const &pattern, vi& prefix_arr){
    int t_size = txt.size(), p_size = pattern.size();
    vi match_locations;
    for(int i=0, j=0; i < t_size;){
        if(txt[i] == pattern[j]){
            ++i, ++j;
            if(j == p_size){
                match_locations.push_back(i-p_size);
                j = prefix_arr[j-1];
            }
        }else if(j > 0) j = prefix_arr[j-1];
        else ++i; 
    } 
    return match_locations;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;
    vi prefix_arr = build_prefix(pattern);
    vi match_locations = find_matches(text, pattern, prefix_arr);
    for(auto v: match_locations) cout << v <<" ";
    cout <<endl;
}
