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

ll gcd(ll a, ll m, ll &x, ll &y){
    if(!(a % m))
        return m;
    ll tmp_x = 0, tmp_y = 0;
    ll gc = gcd(m, a % m, tmp_x, tmp_y);
    x = 1, y = -(a/m);
    if(tmp_x && tmp_y)
        x = x * tmp_y, y = tmp_x + y * tmp_y;
    return gc;
}

ll extended_euclidean(ll a, ll m, ll& x, ll& y){
    /*
     * returns the value of gcd(a, m) and sets x and y to the coefficients of 'a' and 'm'
     * in the Bezout's identity a*x + m*y = gcd(a, m)
     * */
    if(a > m){
        if(!(a % m))
            x = 1, y = -(a / m - 1);
        return gcd(a, m, x, y);
    }
    else{
        if(!(m % a))
            y = 1, x = -(m / a - 1);
        return gcd(m, a, y, x);
    }
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
    cin >> a >> m;
    modular_inverse(a, m);
    return 0;
}
