#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<long> m[1000][2];
int N;
int vals[2];

set<long> solve(int depth, long val) {
  if (depth == N) {
    set<long> v;
    v.insert(val);
    return v;
  }
  if (!m[depth][val].empty()) return m[depth][val];

  int i;
  set<long> s, lefts, rights;

  lefts = solve(depth+1, vals[0]);
  rights = solve(depth+1, vals[1]);

  set<long>::iterator it;
  for (it = lefts.begin(); it != lefts.end(); it++) s.insert(*it + val);
  for (it = rights.begin(); it != rights.end(); it++) s.insert(*it + val);

  return m[depth][val] = s;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin >> N >> vals[0] >> vals[1];

    set<long> s = solve(1, 0);

    set<long>::iterator it = s.begin();
    cout << *it; it++;
    for (; it != s.end(); it++)
      cout << ' ' << *it;
  }
  cout << endl;

  return 0;
}
