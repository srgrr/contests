#include <iostream>
#include <vector>
using namespace std;

int p1[4][4] = {
  {1, 0},
  {0, 1},
};

int p2[4][4] = {
  {0, 1},
  {1, 0}
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        int rpar = i / 2, cpar = j / 2;
        int ci = i % 2, cj = j % 2;
        if(cpar % 2 == 0 ^ rpar % 2 == 0) {
          cout << p1[ci][cj] << " ";
        }
        else {
          cout << p2[ci][cj] << " ";
        }
      }
      cout << endl;
    }
  }
}
