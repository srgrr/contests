#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    int pos = 0, neg = 0;
    multiset< int > nums;
    for(int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if(x < 0) ++neg;
      else if(x > 0) ++pos;
      if(x != 0 || nums.count(0) < 3)
        nums.insert(x);
    }
    if(pos >= 3 || neg >= 3) {
      printf("NO\n");
    }
    else {
      bool ok = true;
      vector< int > v(nums.begin(), nums.end());
      for(int i = 0; i < v.size() && ok; ++i)
        for(int j = i + 1; j < v.size() && ok; ++j)
          for(int k = j + 1; k < v.size() && ok; ++k)
            ok &=  nums.count(v[i] + v[j] + v[k]) > 0;
      printf("%s\n", (ok ? "YES" : "NO"));
    }
  }
}
