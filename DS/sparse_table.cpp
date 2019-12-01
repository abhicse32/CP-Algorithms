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

/*The idea behind the sparse tables is that, we store the result of applying the given
 * function on a range of a power of 2 for each index. We use a table st where st[i][j] will
 * store the result of operation on interval [i, 2^(j-1)-1]*/
vii st;
auto min = [](const int& num1, const int& num2){return num1 > num2? num2: num1;};
auto max = [](const int& num1, const int& num2){return num1 > num2? num1: num2;};
auto sum = [](const int& num1, const int& num2){return num1+num2;};
void build_table(){}

int main(){
}
