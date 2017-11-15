#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
const ll M = 1000000007;
map<ll, ll> F;

ll fibonacci(ll n) {
	if (F.count(n)) {
        return F[n];
    }
	ll k=n/2;
    if (n%2==0) { // n=2*k
        F[n] = (fibonacci(k)*fibonacci(k) + fibonacci(k-1)*fibonacci(k-1)) % M;
    } else { // n=2*k+1
        F[n] = (fibonacci(k)*fibonacci(k+1) + fibonacci(k-1)*fibonacci(k)) % M;
    }
    return F[n];
}

int main(void){
	ll n;
    F[0]=F[1]=1;
	if (cin >> n) {
		if (n==0) 
			cout << 0 << endl;
		else {
			cout << fibonacci(n-1) << endl;
        }
	}
	return 0;
}