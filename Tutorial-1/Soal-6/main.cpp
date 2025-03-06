#include <iostream>
#include "BigNumber.hpp"
using namespace std;

ostream& operator<<(ostream& os, const BigNumber& bn) {
  bool foundNonZero = false;
  for (int i = BigNumber::getMaxDigit() - 1; i >= 0; i--) {
    if (bn[i] > 0) {
      foundNonZero = true;
    }
    if (foundNonZero) {
      os << bn[i];
    }
  }
  if (!foundNonZero) {
    os << "0";
  }
  return os;
}

int main() {
  BigNumber a(123), b("2210");
  cout << a << endl; // 123
  cout << b << endl; // 2210
  cout << (a < b) << endl; // 1
  cout << (a > b) << endl; // 0
  cout << (a + b) << endl; // 2333
  return 0;
}