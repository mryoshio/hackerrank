#include <iostream>
using namespace std;

void solve() {
  int t;
  cin >> t;
  while(t--) {
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size()/2; i++)
      cnt += abs(s[i] - s[s.size()-1-i]);
    cout << cnt << endl;
  }
}

int main() {
  solve();
  return 0;
}
