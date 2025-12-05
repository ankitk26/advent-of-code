#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void traverseGrid(int x, int y, vector<vector<char>> &grid, char direction) {
    int i = x, j = y;
    char newDirection;

    if (direction == 'N') {
        while (i >= 0 && grid[i][j] != '#') {
            if (grid[i][j] != '#') {
                grid[i][j] = 'X';
            }
            i--;
        }
        i++;
        newDirection = 'E';
    } else if (direction == 'E') {
        while (j < grid[0].size() && grid[i][j] != '#') {
            if (grid[i][j] != '#') {
                grid[i][j] = 'X';
            }
            j++;
        }
        j--;
        newDirection = 'S';
    } else if (direction == 'S') {
        while (i < grid.size() && grid[i][j] != '#') {
            if (grid[i][j] != '#') {
                grid[i][j] = 'X';
            }
            i++;
        }
        i--;
        newDirection = 'W';
    } else {
        while (j >= 0 && grid[i][j] != '#') {
            if (grid[i][j] != '#') {
                grid[i][j] = 'X';
            }
            j--;
        }
        j++;
        newDirection = 'N';
    }

    if (i <= 0 || j <= 0 || i + 1 >= grid.size() || j + 1 >= grid[0].size()) {
        int sum = 0;
        for (int a = 0; a < grid.size(); a++) {
            for (int b = 0; b < grid[0].size(); b++) {
                if (grid[a][b] == 'X') {
                    sum++;
                }
            }
        }
        cout << sum << endl;
        return;
    }

    traverseGrid(i, j, grid, newDirection);

}

int main() {
    int n = 130;

    vector<vector<char>> grid(n, vector<char>(n));

    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '^') {
                x = i; y = j;
            }
            grid[i][j] = c;
        }
    }

    traverseGrid(x, y, grid, 'N');


    return 0;
}
