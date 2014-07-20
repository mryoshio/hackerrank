#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int can_make_palindrome(const string s) {
  int data[26];
  fill(data, data + 26, 0);

  for (string::const_iterator it = s.begin(); it != s.end(); it++)
    data[(*it) - 'a'] ^= 1;

  int odds = 0;
  int evens = 0;

  for (int i = 0; i < 26; i++) {
    if (data[i] == 0) evens++;
    else odds++;
  }

  if (s.size() %2) {
    if (odds == 1) return 1;
  } else {
    if (odds == 0) return 1;
  }
  return 0;
}

int main() {
   
  string s;
  cin>>s;

  int flag = 0;

  flag = can_make_palindrome(s);
     
  if(flag==0)
    cout<<"NO";
  else
    cout<<"YES";
  return 0;
}
