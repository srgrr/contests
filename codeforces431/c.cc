#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int mod = 1000000007;

int calc(
  map< vector< int>, int>& dp,
  int n,
  int k,
  int d,
  int cur,
  int alr) {

  if(cur == n && alr) {
    return 1;
  }

  vector< int > state = {cur, alr};

  if(dp.count(state)) {
    return dp[state];
  }

  auto& ret = dp[state];
  ret = 0;

  for(int i = 1; i <= k; ++i) {
    int nalr = alr | (i >= d);
    int nw = cur + i;
    if(nw <= n) {
      ret += calc(dp, n, k, d, nw, nalr);
      ret %= mod;
    }
  }

  return ret;
}


int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  map< vector< int >, int> dp;
  printf("%d\n", calc(dp, n, k, d, 0, 0));
}
