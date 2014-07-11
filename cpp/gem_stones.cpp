#include <iostream>
#include <map>

using namespace std;

void solve() {
  string s;
  map<char, int> m;

  for (char c = 'a'; c != 'z'; c++) m[c] = 0;

  cin >> s;
  for (string::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << endl;
    cout << m['a'] << endl;
    cout << m['b'] << endl;
  }
}

int main() {
  solve();
  return 0;
}
