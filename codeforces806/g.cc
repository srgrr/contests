#include <cstdio>
#include <vector>
using namespace std;
typedef long long int ll;
const ll inf = 10000000000000ll;

ll calc(vector< vector< ll > >& dp, vector< ll >& v, int k, int i, int j) {
  if(i == dp.size()) {
    return 0ll;
  }

  ll& ref = dp[i][j];

  if(ref == -inf) {
    ref = (v[i] >> ll(j)) - ll(k) + calc(dp, v, k, i + 1, j);
    int j2 = min(j + 1, int(dp[0].size()) - 1);
    ref = max(ref, (v[i] >> ll(j2)) + calc(dp, v, k, i + 1, j2));
  }

  return ref;
}


int main() {
  int T;
  scanf("%d", &T);

  while(T--) {
    int n, k;
    scanf("%d %d", &n, &k);

    vector< ll > v(n);

    for(ll& x: v) {
      scanf("%lld", &x);
    }

    vector< vector< ll > > dp(n, vector< ll >(31, -inf));
    
    printf("%lld\n", calc(dp, v, k, 0, 0));
  }
}
