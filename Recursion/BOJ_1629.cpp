// a power of n * a power of n = a power of 2n
#include <iostream>
#define ll long long
using namespace std;

ll pow(ll a, ll n, ll m) {
    ll remainder;
    if(n == 0) return 1 % m;
    else if(n == 1) return a % m;
    else {
        remainder = pow(a, n / 2, m);
        remainder = remainder * remainder % m;
        if(n % 2 == 0) {
            return remainder;
        } else {
            return remainder * a % m;
        }
    }
}

int main() {
    int a, n, m;
    cin >> a >> n >> m;
    cout << pow(a, n, m);
    return 0;
}