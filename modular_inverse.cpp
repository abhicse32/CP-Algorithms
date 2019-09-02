#include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define vii vector<vi>
#define mii map<ll, ll>
#define si set<ll>
#define sci(n) scanf("%d",&n)
#define sti stack<ll>
#define qi queue<ll>
#define pii pair<ll,ll>
#define ll long long

/*
 * bezout's identity is: ax + my = gcd(a, m). the cofficients x and y can be found working the 
 * euclidean gcd backwards and the same can be computed whlie keeping track of coefficients in each
 * step of the recursive implementation.
 * Since next step of the gcd(a, m)  is gcd(m, a%m) which means gcd(a, m) = gcd(m, a % m) = a * x + m * y
 * Let's suppose coefficients for gcd(m, a % m) are x1 and y1, then using Bezout's identity, we can write-
 * m * x1 + (a % m) * y1 = gcd(m, a % m) = gcd(a, m) = a*x + m*y
 *  => m*x1 +(a - m*(a/m)) * y1 = a*x + m*y 
 *  => a*y1 + m*(x1 - (a/m)*y1) = a*x + m*y
 *  => x = y1 and y = x1 - (a/m)
 * */
ll extended_euclidean(ll a, ll m, ll &x, ll &y){
    if(!m){
        x = 1, y= 0;
        return a;
    }
    ll tmp_x, tmp_y;
    ll gc = extended_euclidean(m, a % m, tmp_x, tmp_y);
    x = tmp_y, y = tmp_x - (a/m) * tmp_y;
    return gc;
}

void modular_inverse(ll a, ll m){
    ll x, y;
    ll gcd = extended_euclidean(a, m, x, y);
    if(gcd!=1)
        cout << "No Solution!\n";
    else
        cout <<"Modular inverse of " << a <<" mod " << m <<": " << (x % m + m) % m <<endl;

    printf("Bezout's Identity: %lld*%lld + %lld*%lld = %lld", a,x,m,y, gcd);
}

int main(){
    ll a, m;
    while(1){
        cin >> a >> m;
        modular_inverse(a, m);
    }
    return 0;
}
