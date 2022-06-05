#include <iostream>
#define ll long long
#define display(n) cout << n << " "

using namespace std;

void solve(ll n) {
	if (n > 0) {
		display(n);
		if (n != 1) {
			do {
				if (n % 2 == 0) {
					n /= 2;
					display(n);
				} else if (n % 2 != 0) {
					n = 3 * n + 1;
					display(n);
				}
			} while (n != 1);
		}
	}
}

int main() {
	ll n;
	cin >> n;
	solve(n);
	return 0;
}
