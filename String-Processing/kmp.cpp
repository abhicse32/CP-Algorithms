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
#define vll vector<ll>

vi prefix_arr;
void build_prefix_arr(string& str){
    int n = str.size();
    prefix_arr.assign(n, 0);
    for(int i=1, j;i<n;++i){
       j = prefix_arr[i-1];
       while(j > 0 && str[i] != str[j]) j = prefix_arr[j-1];
       if(str[i] == str[j]) ++j;
       prefix_arr[i] = j;
    }    
} 

vi get_occurrences(string& txt, string& pattern){
    build_prefix_arr(pattern);
    vi occur_indices;
    int txt_size = txt.size(), pat_size = pattern.size();
    for(int i=0, j = 0;i < txt_size; ++i){
        while(j > 0 && txt[i] != pattern[j]) j = prefix_arr[j];
        if(txt[i] == pattern[j]) ++j;
        if(j >= pat_size){
           occur_indices.push_back(i-j+1);
           j = prefix_arr[j-1];
        }
    }  
    return occur_indices;
} 

void compute_automaton(string& str, vii& automaton){
    str += '#' // assuming that only lower english alphabet characters will appear in the string
    int n = str.size();
    build_prefix_arr(str);
    automaton.assign(n, vi(26));
    for(int i = 0; i< n; ++i){
        for(int c = 0; c < 26; ++c){
            int j = i;
            while(j > 0 && 'a' + c != str[j])
                j = prefix_arr[j-1];
            if('a' + c == str[j])
                ++j;
            automaton[i][c] = j;
        }
    }  
}

int main(){
    string txt = "abcabdabcabd", pattern = "abcab";
    vi indices = get_occurrences(txt, pattern); 
    for(auto v: indices) cout << v <<" ";
    cout <<endl;
}
