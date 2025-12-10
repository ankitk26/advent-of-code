#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
	int n = 496;

	vector<vector<ll>> grid(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		size_t pos = s.find(",");

		int left = stoi(s.substr(0, pos));
		int right = stoi(s.substr(pos + 1));

		grid[i] = {left, right};
	}

	ll maxArea = -1;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll currArea = (abs(grid[i][0] - grid[j][0]) + 1) * (abs(grid[i][1] - grid[j][1]) + 1);
			maxArea = max(maxArea, currArea);
		}
	}

	cout << maxArea;

	return 0;
}
