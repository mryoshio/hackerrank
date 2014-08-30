#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> m[1000][2];
int N;
int vals[2];

vector<long> solve(int depth, long val) {
  if (depth == N) {
    vector<long> v;
    v.push_back(val);
    return v;
  }
  int i;
  vector<long> s, lefts, rights;

  lefts = solve(depth+1, vals[0]);
  rights = solve(depth+1, vals[1]);

  vector<long>::iterator it;

  for (it = lefts.begin(); it != lefts.end(); it++) s.push_back(*it + val);
  for (it = rights.begin(); it != rights.end(); it++) s.push_back(*it + val);

  sort(s.begin(), s.end());
  vector<long>::iterator last = unique(s.begin(), s.end());

  s.resize(last - s.begin());

  return m[depth][val] = s;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> N >> vals[0] >> vals[1];
    vector<long> s = solve(1, 0);
    sort(s.begin(), s.end());
    vector<long>::iterator last = unique(s.begin(), s.end());
    vector<long>::iterator it = s.begin();
    cout << *it; it++;
    for (; it != last; it++)
      cout << ' ' << *it;
  }
  cout << endl;

  return 0;
}
