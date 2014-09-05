#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;

void solve() {
  long cnt = 0;
  int i1 = 0;
  int i2 = 0;
  do {
    if (s1[i1] < s2[i2]) {
      if (i1 == s1.size()) { 
        i2++; cnt++;
      } else if (i1 != s1.size()) { 
        i1++; cnt++;
      } 
    } else if (s1[i1] > s2[i2]) {
      if (i2 == s2.size()) { 
        i1++; cnt++;
      } else if (i2 != s2.size()) { 
        i2++; cnt++; 
      }
    } else {
      if (i1 != s1.size()) { i1++; }
      if (i2 != s2.size()) { i2++; }
    }
  } while (i1 != s1.size() || i2 != s2.size());
  cout << cnt << endl;
}

int main() {
  cin >> s1 >> s2;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  solve();
  return 0;
}
