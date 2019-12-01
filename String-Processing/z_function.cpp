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

vi z_function_trivial(string& str){
    int n = str.size();
    vi z_arr(n, 0);
    for(int i=1; i< n ;++i){
       while(i + z_arr[i] < n && str[z_arr[i]] == str[i + z_arr[i]])
          ++z_arr[i]; 
    }    
    return z_arr;
}

vi z_function(string &str){
    int n = str.size();
    vi z_arr(n, 0);
    for(int i=1, l=0, r=0; i< n; ++i){
        z_arr[i] = i>r?0:min(z_arr[i-l], r-i+1); 
        while(i + z_arr[i] < n && str[i]==str[i+z_arr[i]])
           ++z_arr[i]; 
        if(i + z_arr[i] -1 > r)
            r = z_arr[i] + i - 1, l = i;
    }
    return z;
}

int main(){
    string str = "aaaabaabaa";
    vi z_arr = z_function_trivial(str);
    for(auto v: z_arr) cout << v <<" ";
    cout <<endl;
}
