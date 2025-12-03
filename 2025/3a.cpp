#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
  int n = 200;

  int sum = 0;

  while (n--) {
    string s; cin >> s;

    char f = '0';
    int fi = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] > f) {
        f = s[i];
        fi = i;
      }
    }

    char sf = '0';
    for (int i = fi + 1; i < s.size(); i++) {
      sf = max(sf, s[i]);
    }

    int num = (int)(f - '0') * 10 + (int)(sf - '0');
    sum += num;
  }

  cout << sum;

  return 0;
}
