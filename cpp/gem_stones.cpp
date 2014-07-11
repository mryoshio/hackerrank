#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;

void solve() {
  string s;
  queue<char> q;

  for (int i = 0; i < 26; i++)
    q.push('a' + i);

  for (int i = 0; i < N; i ++) {
    cin >> s;
    for (int j = 0, c_max = q.size(); j < c_max; j++) {
      char v = q.front(); q.pop();
      if (find(s.begin(), s.end(), v) != s.end())
        q.push(v);
    }
  }
  cout << q.size() << endl;
}

int main() {
  cin >> N;
  solve();
  return 0;
}
