#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll m = 1e9 + 7;

//exponential for a^b
ll calc(ll a, ll b) {
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
    ll a, b;
    cin >> a >> b;
    b %= (m-1);
    cout << calc(a, b) % m << endl;
    return 0;
}