#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll m = 1e9 + 7;

//exponential for a^b^c
ll calc(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        (b % 2 == 1)? res = (res * a) % m : 0;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
 
int main(){
    ll a, b, c, pow;
    cin >> a >> b >> c;
    pow = calc(b, c, m-1);
    cout << calc(a, pow, m) % m << endl;
    return 0;
}