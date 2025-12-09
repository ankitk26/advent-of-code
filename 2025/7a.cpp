#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

void splitBeams(int &ans, vector<string> &grid, int row, int col) {
	if (row > grid.size() || col > grid[0].size() || col < 0) {
		return;
	}

	bool foundSplitter = 0;

	while (row < grid.size()) {
		if (grid[row][col] == 'X') {
			break;
		}

		if (grid[row][col] == '^') {
			foundSplitter = 1;
			grid[row][col] = 'X';
			break;
		}
		row++;
	}

	if (foundSplitter) {
		ans++;
		splitBeams(ans, grid, row, col - 1);
		splitBeams(ans, grid, row, col + 1);
	}
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

	int ans = 0;
	splitBeams(ans, grid, si, sj);

	cout << ans;

	return 0;
}
