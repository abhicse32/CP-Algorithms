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

/* Euclidean method to compute gcd of two numbers can't be defined as gcd(a, b) = gcd(b, a%b). This
 * is guaranteed to terminate as one of the operators keeps decreasing until it reaches 0. Proof of why 
 * we write gcd(a, b) = gcd(b, a%b). Let's assume gcd(a, b) = d. This implies that d|a and d|b. we can write,
 * a%b = a - b*floor(a/b). As we know that d|a and d|b => d|(a-b*floor(a/b)) => d|(a%b). Since d|b as well =>
 * d = gcd(b, a%b)*/

ll gcd(ll a, ll b){
    return b?gcd(b, a % b): a;
}

ll gcd_iter(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a; 
}

/*
 * lcm of two integers can be computed as -> lcm(a, b) = gcd(a, b) * (a/gcd(a,b)) *(b/gcd(a,b)) = (a*b) / gcd(a, b);
 * */

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return (a*b)/g;
}

int main(){
    ll a, b;
    while(true){
        cin >> a >> b;
        cout << gcd_iter(a, b) <<endl;
    }
    
}
