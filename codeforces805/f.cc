#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int simplify(int x) {
  while(x % 2 == 0) x /= 2;
  return x;
}


int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    multiset< int > A;
    for(int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      x = simplify(x);
      A.insert(x);
    }
    multiset< int > B;
    for(int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      B.insert(x);
    }
    while(!B.empty()) {
      int x = *B.rbegin();
      if (!A.count(x)) {
        if (x == 1) break;
        B.erase(B.find(x));
        B.insert(x / 2);
      } else {
        B.erase(B.find(x));
        A.erase(A.find(x));
      }
    }
    printf("%s\n", (B.empty() ? "YES" : "NO"));
  }
}
