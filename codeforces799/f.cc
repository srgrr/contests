#include <cstdio>
#include <vector>
using namespace std;


bool calc(vector< int >& v, int lv, int accm) {
  if(lv == 3) return accm == 3;
  bool any = false;
  for(int i = 0; i < 10; ++i) {
    if(v[i] > 0) {
      --v[i];
      any |= calc(v, lv + 1, (accm + i) % 10);
      ++v[i];
    }
  }
  return any;
}


int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    vector< int > v(10, 0);
    for(int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      ++v[x % 10];
    }
    printf("%s\n", (calc(v, 0, 0) ? "YES" : "NO"));
  }
}
