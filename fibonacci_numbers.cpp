#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define vl vector<ll>
#define vll vector<vl>
inline ll compute(vll& src_arr, int r, vll& dest_arr, int c){
    return ((src_arr[r][0] * dest_arr[0][c]) % mod + (src_arr[r][1] * dest_arr[1][c]) % mod) % mod;
}

void matrix_mult(vll& src_arr, vll& dest_arr){
    ll a_00 = compute(src_arr, 0, dest_arr, 0);
    ll a_01 = compute(src_arr, 0, dest_arr, 1);
    ll a_10 = compute(src_arr, 1, dest_arr, 0);
    ll a_11 = compute(src_arr, 1, dest_arr, 1);
    dest_arr[0][0] = a_00, dest_arr[0][1] = a_01;
    dest_arr[1][0] = a_10, dest_arr[1][1] = a_11;
}

ll matrix_exp(ll n){
    vll P{vl{0, 1}, vl{1, 1}};
    vll res_matrix{vl{1, 0}, vl{0, 1}};
    while(n){
        if(n&1)
            matrix_mult(P, res_matrix);
        matrix_mult(P, P);
        n >>= 1;
    }
    return res_matrix[1][0];
}

// Uses the formula derived from the identity F(n+k) = f(k)f(n+1) + f(k-1)f(n)
// f(2k) = f(k)(2f(k+1) - f(k)), f(2k+1) = f(k+1)^2 + f(k)^2
pair<ll, ll> fast_doubling(ll n){
    if(!n)
        return {0, 1}; 
    pair<ll, ll> p = fast_doubling(n >> 1);
    ll c = p.first * ((p.second << 1) - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if(n&1) return {d, c + d};
    return {c, d};
}
    
int main(){
    cout << matrix_exp(29) <<endl; 
    cout << fast_doubling(29).first <<endl;
}
