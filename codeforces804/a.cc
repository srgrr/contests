#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n == 2) {
      cout << "1 1 0" << endl;
    }
    else if(n % 4 == 0) {
      cout << n / 2 + 1 << " " << n / 2 + 1 << " 1" << endl;
    }
    else if(n % 2 == 0) {
      cout << n / 2  << " " << n / 2  << " 0" << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
}
