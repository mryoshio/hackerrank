#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n, k;
  cin >> n;
  cin >> k;

  long v = 0;  
  vector<long> packets;
  for (long i = 0; i < n; i++) {
    cin >> v;
    packets.push_back(v);
  }
  sort(packets.begin(), packets.end());
  cout << (packets[k-1] - packets.front());
  return 0;
}
