#include <_types/_uint64_t.h>
#include <iostream>
#include <string>
#include <vector>
#define u64 uint64_t

using namespace std;

struct Position {
	u64 row;
	u64 col;
	Position(u64 row, u64 col) : row{row}, col{col} {}
};

u64 calculate(u64 large, u64 small) {
	auto start_point = large * large;
	auto p = start_point - small + 1;
	return p;
}

u64 judgement(u64 row, u64 col) {
	if (row == 1 && col == 1) {
		return 1;
	}
	return row > col ? calculate(row, col) : calculate(col, row);
}

vector<u64> solve(const vector<Position>& v) {
	vector<u64> result;
	for (auto x : const_cast<vector<Position>&>(v)) {
		auto r = judgement(x.row, x.col);
		result.push_back(r);
	}
	return result;
}

int main() {
	vector<Position> v;
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> ws;
		u64 row; u64 col;
		cin >> row >> col;
		Position p = Position(row, col);
		v.push_back(p);
	}
	auto results = solve(v);
	for (auto result : results) {
		cout << result << endl;
	}
}
