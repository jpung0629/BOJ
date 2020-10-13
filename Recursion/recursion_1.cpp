#include <iostream>
using namespace std;

int pow(int a, int n) {
    if(n == 0) return 1;
    else {
        return pow(a, n-1) * a;
    }
}

int main() {
    int a, n;
    cout << "a: ";
    cin >> a;
    cout << "n: ";
    cin >> n;
    cout << pow(a, n);
    return 0;
}