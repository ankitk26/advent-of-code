#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

ll splitBeams(vector<string> &grid, int row, int col, vector<vector<ll>> &dp) {

	if (col >= grid[0].size() || col < 0 || row > grid.size()) return 0;

	while (row < grid.size()) {
		if (grid[row][col] == '^') {
			break;
		}
		row++;
	}

	if (row == grid.size()) {
		return 1;
	}

	if (dp[row][col] != -1) {
		return dp[row][col];
	}

	ll currAns = splitBeams(grid, row, col - 1, dp) + splitBeams(grid, row, col + 1, dp);
	return dp[row][col] = currAns;
}

int main() {
	int n = 142;
	vector<string> grid(n);

	int si = 0, sj = 0;

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 'S') {
				si = i;
				sj = j;
				break;
			}
		}
	}

	int firstSplitRow = si;
	while (firstSplitRow < n && grid[firstSplitRow][sj] != '^') {
		firstSplitRow++;
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(grid[0].size() + 1, -1));

	splitBeams(grid, si + 1, sj, dp);
	cout << dp[firstSplitRow][sj] << endl;

	return 0;
}
