#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string line1, line2;
  cin >> line1;
  cin >> line2;

  cout << (line1.length() < line2.length() ? "no" : "go") << endl;
}
