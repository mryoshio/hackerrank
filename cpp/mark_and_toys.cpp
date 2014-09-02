#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long i, n, k; cin >> n >> k;
  vector<long> prices;
  for(i = 0; i < n; i++) {
    long p; cin >> p;
    prices.push_back(p);
  }
  sort(prices.begin(), prices.end());
  for (i = 0; i < n; i++) {
    k -= prices[i];
    if (k <= 0) break;
  }
  cout << i << endl;
  return 0;
}
