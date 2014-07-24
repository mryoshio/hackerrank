#include <iostream>
#include <climits>

using namespace std;

int s;
int ar[1001];

void d() {
  for (int i = 0; i < s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void insertionSort(int ar[]) {
  if (s == 1) return;

  int i;
  bool insertable;

  do {
    insertable = false;
    for (i = 1; i < s; i++) {
      if (ar[i-1] > ar[i]) {
        insertable = true;
        break;
      }
    }
    
    if (insertable) {
      int tmp;
      int idx = s-1;
      while (i < idx) {
        tmp = ar[idx];
        ar[idx] = ar[idx-1];
        ar[idx-1] = tmp;
        idx--;
      }
      tmp = ar[i];
      ar[i] = ar[i-1];
      ar[i-1] = tmp;
      d();
      insertable = true;
    }
  } while (insertable);
  d();
}

int main() {
  cin >> s;
  for (int i = 0; i < s; i++)
    cin >> ar[i];
  insertionSort(ar);
  return 0;
}
