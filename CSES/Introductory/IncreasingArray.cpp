#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long> fetch_numbers(const string& input) {
	vector<long> numbers;
	string digit;
	for (auto x : const_cast<string&>(input)) {
		if (x != ' ') {
			digit += x;
		} else {
			long num = stol(digit);
			numbers.push_back(num);
			digit = "";
		}
	}
	return numbers;
}

void solve(vector<long> v) {
	long moves {0};
	long largest {0};
	for (auto lhs = v.begin(), rhs = ++v.begin(); rhs != v.end(); lhs++, rhs++) {
		if (largest < *lhs) {
			largest = *lhs;
		}
		if (largest <= *rhs) {
			continue;
		}
		moves += (largest - *rhs);
	}
	cout << moves << endl;
}

int main() {
	long range;
	cin >> range;
	cin >> ws;
	string input;
	getline(cin, input);
	input += ' ';
	vector<long> numbers = fetch_numbers(input);
	solve(numbers);
	return 0;
}
