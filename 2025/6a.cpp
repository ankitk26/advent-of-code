#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
	int n = 5;

	vector<vector<ll>> grid;
	vector<ll> ops;

	while (n--) {
		string s;
		getline(cin, s);

		string curr;
		vector<ll> row;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (curr.size() > 0) {
					if (curr == "*") {
						row.push_back(1);
					} else if (curr == "+") {
						row.push_back(0);
					} else {
						row.push_back(stoll(curr));
					}
				}
				curr = "";
			} else {
				curr += s[i];
			}
		}
		if (curr.size() > 0) {
			if (curr == "*") {
				row.push_back(1);
			} else if (curr == "+") {
				row.push_back(0);
			} else {
				row.push_back(stoll(curr));
			}
		}

		grid.push_back(row);
	}

	int rows = grid.size(), cols = grid[0].size();

	ll ans = 0;

	for (int j = 0; j < cols; j++) {
		ll currTotal = 0;
		int op = grid[rows - 1][j];
		if (op == 1) {
			currTotal = 1;
		}
		for (int i = 0; i < rows - 1; i++) {
			if (op == 1) {
				currTotal *= grid[i][j];
			} else {
				currTotal += grid[i][j];
			}
		}
		ans += currTotal;
	}

	cout << ans;

	return 0;
}
