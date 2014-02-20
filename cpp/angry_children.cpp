#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  long n, k;
  cin >> n >> k;

  vector<long> packets;
  packets.assign(n, LONG_MAX);
  for (long i = 0; i < n; i++)
    cin >> packets[i];

  sort(packets.begin(), packets.end());
  long diff, unfairness = LONG_MAX;

  for (int i = 0; i + k <= packets.size(); i++) {
    diff = packets[i + k - 1] - packets[i];
    if (diff < unfairness)
      unfairness = diff;
  }

  cout << unfairness;
  return 0;
}
