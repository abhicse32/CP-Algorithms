#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define mii map<int, int>
#define si set<int>
#define sci(n) scanf("%d",&n)
#define scii(n, m) scanf("%d%d",&n,&m)
#define sti stack<int>
#define qi queue<int>
#define pii pair<int,int>
#define ll long long
#define MAXN 100005
/*
 * Usage: finding range queries on static arrays
 * */
int K = 30;
vii st;
vi max_pow2(MAXN, 0);

inline int sum(int &num1, int &num2){
    return num1 + num2;
}
inline int min(int &num1, int &num2){
    return num1 > num2 ? num2: num1;
}
inline int max(int &num1, int &num2){
    return num1 > num2 ? num1: num2;
}

void pre_compute(vi& arr, int n, int (&func)(int&, int&)){
   for(int i=0;i < n; ++i)
       st[i][0] = arr[i];
   for(int j=1;j<=K;++j){       
       int pow_2j = (1<<j);
       for(int i=0;i+pow_2j <= n;++i)
            st[i][j] = func(st[i][j - 1], st[i+ (pow_2j >> 1)][j-1]);
   }
}

int get_largest_pow2(int range){
    int len = -1;
    while(range) ++len, range >>= 1;
    return len;
}

// O(log(N)) query time
int process_query(int l, int r, int (&func)(int&, int&), int init_val = 0){
    // process from higher powers of 2 to lowers ones
    int result = init_val; // for range_sum query 0, for min query INT_MAX for max-query, INT_MIN;
    while(l <= r){
       int k = get_largest_pow2(r - l + 1);
       result = func(result, st[l][k]);
       l = l + (1 << k);
    }    
    return result;
}

// Sparse table performs the best for Range Minimum Queries as it can answer them in O(1) time as following
// in finding the range_minimum query, the entire range is split in only two subranges with the lengths equal
// to the largest power of 2 less than the range length For example- range [L, R] can be split into two overlapping
// ranges [L, L+2^k] and [R-2^k+1, R]. This will require computing the largest power of 2 less than or equal to i
// for each number i in the range [1, n]

void pre_compute_largest_pow2(){ 
    for(int i=2; i< MAXN; ++i)
        max_pow2[i] = max_pow2[i>>1] + 1;
}

int range_min_query(int l, int r){
    int max_exp = max_pow2[r - l + 1];
    return min(st[l][max_exp], st[r- (1 << max_exp) + 1][max_exp]); 
}

int main(){
    int n,i,j,k,q;
    st.assign(MAXN, vi(K, 0));
    scanf("%d%d",&n,&q);
    vi arr(n);
    for(int i=0;i<n;++i) sci(arr[i]);
    pre_compute(arr, n, min);
    pre_compute_largest_pow2();
    while(q--){
        scii(j,k);
        //cout << process_query(j, k, min, INT_MAX) <<endl;
        cout << range_min_query(j, k) <<endl;
    }
    return 0;
}
