#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long int ll;


int main() {
  int n, q, x;
  scanf("%d %d %d", &n, &q, &x);
  vector< int > w(n);
  for(int& wi: w) {
    scanf("%d", &wi);
  }

  vector< ll > pref_sum(n + 1, 0ll);
  for(int i = 1; i <= n; ++i) {
    pref_sum[i] = 1ll * w[i - 1] + pref_sum[i - 1];
  }

  vector<int> boxes(n);

  for(int i = 0; i < n; ++i) {
    int l = i + 1, r = i + x;
    while(l <= r) {
      int h = (l + r) / 2;
      int cycles = h / n, rem = h % n;
      ll total = 1ll * pref_sum.back() * cycles + pref_sum[rem] - pref_sum[i];
      if(total >= x) {
        boxes[i] = h - i;
        r = h - 1;
      }
      else {
        l = h + 1;
      }
    }
  }

  map<int, int> vis;
  int cycle_start = -1;
  vector< int > cycle;
  int i = 0;
  while(cycle_start == -1) {
    if(vis.count(i)) {
      cycle_start = i;
    }
    else {
      vis[i] = cycle.size();
      cycle.push_back(i);
      i = (i + boxes[i]) % n;
    }
  }

  int ini_len = vis[cycle_start];
  int cycle_len = cycle.size() - ini_len;
  for(int i = 0; i < q; ++i) {
    ll k;
    scanf("%lld", &k);
    --k;
    if(k < ini_len) {
      printf("%d\n", boxes[cycle[k]]);
    }
    else {
      int cycle_idx = (k - ini_len) % cycle_len;
      printf("%d\n", boxes[cycle[cycle_idx + ini_len]]);
    }
  }

}
