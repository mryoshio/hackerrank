#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;

void solve(int cnt, int sum, int idx, vector<int> &v, set<int> &ans) {
  sum += v[idx];
  cnt++;
  if (cnt == N) {
    ans.insert(sum);
    return;
  }
  for (int i = 0; i < v.size(); i++)
    solve(cnt, sum, i, v, ans);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    set<int> ans;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < 2; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
      solve(1, 0, i, v, ans);
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
      cout << *it << ' ';
    cout << endl;
  }
  return 0;
}
