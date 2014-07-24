#include <iostream>
#include <climits>

using namespace std;

int s;

void d(int* ar) {
  for (int i = 0; i < s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void insertionSort(int* ar) {
  for (int i = 1; i < s; i++) {
    int t = ar[i];
    if (ar[i-1] > t) {
      int j = i;
      do {
        ar[j] = ar[j-1];
        j--;
      } while(ar[j-1] > t && j > 0);
      ar[j] = t;
    }
    d(ar);
  }
}

int main() {
  int ar[1001];
  cin >> s;
  for (int i = 0; i < s; i++) cin >> ar[i];
  insertionSort(ar);
  return 0;
}
