#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> border;

void d(vector<int> v) {
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
}

long quickSort(vector<int> &v, int left, int right) {
  long cnt = 0;

  if (left < right) {
    int i = left, j = right;
    int p = v[right];

    while (true) {
      while (v[i] < p) i++;
      while (p < v[j]) j--;
      if (i >= j) break;
      
      int tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
      cnt++;

      i++; j--;
    }
    cnt += quickSort(v, left, i-1);
    cnt += quickSort(v, j+1, right);
  }
  return cnt;
}

long insertionSort(vector<int> v) {
  long cnt = 0;
  for (int i = 1; i < v.size(); i++) {
    int t = v[i];
    if (v[i-1] > t) {
      int j = i;
      do {
        v[j] = v[j-1];
        j--;
        cnt++;
      } while(v[j-1] > t && j > 0);
      v[j] = t;
    }
  }
  return cnt;
}

int main(void) {
  vector <int> v;
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  vector<int> v2(n);
  copy(v.begin(), v.end(), v2.begin());

  cout << quickSort(v, 0, v.size()-1) << endl;
  cout << insertionSort(v2) << endl;

  return 0;
}
