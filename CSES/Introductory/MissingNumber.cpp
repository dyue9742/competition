#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

bool less_than(int a, int b) {
	return (a < b);
}

vector<int> fetch_numbers(const string& input) {
	vector<int> numbers;
	string digit;
	for (auto x : const_cast<string&>(input)) {
		if (x == ' ') {
			int num = stoi(digit);
			numbers.push_back(num);
			digit = "";
		} else {
			digit += x;
		}
	}
	return numbers;
}

int main() {
	int range;
	cin >> range;
	cin >> ws;
	string input;
	getline(cin, input);
	input += ' ';
	vector<int> numbers = fetch_numbers(input);
	sort(numbers.begin(), numbers.end(), less_than);

	int result {};
	for (int i = 1; i <= range; i++) {
		if (i == numbers[i-1]) {
			continue;
		}
		result = i;
		break;
	}
	cout << result << endl;

	return 0;
}
