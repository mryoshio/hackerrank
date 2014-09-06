#include <iostream>
#include <vector>
using namespace std;

void d(vector<int> v) {
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;
}

void swap(vector<int> &v, int i1, int i2) {
  int t = v[i1];
  v[i1] = v[i2];
  v[i2] = t;
}

long strange_quick_sort(vector<int> &v, int left, int right) {
  if (left >= right) return 0;
  long cnt = 0;
  int cur = left;
  int piv = v[right];

  for (int i = left; i < right; i++) {
    if (v[i] < piv) {
      swap(v, i, cur++);
      cnt++;
    }
  }
  swap(v, cur, right); cnt++;
  cnt += strange_quick_sort(v, left, cur-1);
  cnt += strange_quick_sort(v, cur+1, right);
  return cnt;
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

  cout << insertionSort(v2) - strange_quick_sort(v, 0, v.size()-1) << endl;
  return 0;
}
