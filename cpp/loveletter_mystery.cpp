#include <iostream>
using namespace std;

int T;

bool is_palindrome(string s) {
  bool ret = true;
  for (int i = 0; i < s.size()/2; i++)
    if (s[i] != s[s.size()-1-i])
      return false;
  return true;
}

void solve() {
  string s;

  for (int i = 0; i < T; i++) {
    int cnt = 0, idx = 0;
    cin >> s;
    do {
      if (s[idx] == s[s.size()-1-idx] || s[s.size()-1-idx] == 'a') {
        idx++;
      } else {
        s[s.size()-1-idx]--;
        cnt++;
      }
    } while (!is_palindrome(s));
    cout << cnt << endl;
  }
}

int main() {
  cin >> T;
  solve();
  return 0;
}
