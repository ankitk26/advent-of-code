#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    int ans = 0;

    int n1 = 1176;
    // int n1 = 21;
    unordered_map<int, vector<int>> mp;
    while (n1--) {
        string s;
        getline(cin, s);

        int a = stoi(s.substr(0, 2)), b = stoi(s.substr(3, 2));
        if (mp.find(a) == mp.end()) {
            mp[a] = {b};
        } else {
            mp[a].push_back(b);
        }
    }

    int n2 = 174;
    // int n2 = 6;
    while (n2--) {
        string s; getline(cin, s);

        vector<int> updates;
        unordered_map<int, int> req;

        // take input
        for (int i = 0; i < s.size(); i += 3) {
            int num = stoi(s.substr(i, 2));
            updates.push_back(num);
            req[num]++;
        }

        // get correct sequence
        vector<int> sorted(updates.size());
        for (int i = 0; i < updates.size(); i++) {
            int m = 0;
            for (auto k : mp[updates[i]]) {
                if (req.find(k) != req.end()) {
                    m++;
                }
            }
            sorted[m] = updates[i];
        }
        reverse(sorted.begin(), sorted.end());

        // compare given sequence and its correctly sorted version
        int flag = 0;
        for (int i = 0; i < updates.size(); i++) {
            if (updates[i] != sorted[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            ans += updates[updates.size() / 2];
        }
    }

    cout << ans << endl;
    return 0;
}
