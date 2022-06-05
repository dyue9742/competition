#include <iostream>
#include <string>

using namespace std;

void solve(string s) {
	int current {1};
	int maximum {1};

	for (int i = 0; i <= int(s.length()); i++) {
		if (s[i] == s[i+1]) {
			current++;
		} else {
			if (maximum < current) {
				maximum = current;
			}
			current = 1;
		}
	}
	cout << maximum << endl;
}

int main() {
	string dna;
	cin >> dna;
	solve(dna);
	return 0;
}
