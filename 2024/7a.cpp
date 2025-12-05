#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

bool check(ll result, ll target, char op, ll index, vector<ll> &values) {
    if (index == values.size()) {
        if (result == target) {
            return true;
        }
        return false;
    }

    ll currResult = result;
    if (op == '+') {
        currResult += values[index];
    } else {
        currResult *= values[index];
    }

    bool pickAdd = check(currResult, target, '+', index + 1, values);
    bool pickMult = check(currResult, target, '*', index + 1, values);

    return pickAdd || pickMult;

}

int main() {
    ll n = 850;
    ll ans = 0;

    while (n--) {
        string s;
        getline(cin, s);
        ll target;
        vector<ll> values;

        string curr;
        ll breakIndex = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (s[i] == ':') {
                target = stoull(curr);
                breakIndex = i + 2;
                break;
            } else {
                curr += s[i];
            }
        }
        curr = "";
        for (ll i = breakIndex; i < s.size(); i++) {
            if (s[i] == ' ') {
                values.push_back(stoull(curr));
                curr = "";
            } else {
                curr += s[i];
            }
        }
        values.push_back(stoull(curr));

        bool isPossible = check(0, target, '+', 0, values);
        if (isPossible) {
            ans += target;
        }
    }

    cout << ans << endl;
    return 0;
}
