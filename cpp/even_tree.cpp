#include <iostream>
#include <array>
#include <set>

using namespace std;

array<set<int>, 101> g;
int cut = 0;

int dfs(int node) {
  set<int> children = g[node];
  int cnt = 1;
  set<int>::iterator it = children.begin();
  while (it != children.end()) {
    cnt += dfs(*it);
    it++;
  }
  if (cnt > 1 && cnt % 2 == 0)
    cut++;
  return cnt;
}

int main() {
  int N, M, s, e;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> e >> s;
    g[s].insert(e);
  }
  dfs(1);
  cout << --cut << endl;
  return 0;
}
