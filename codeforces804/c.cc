#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;
const int maxn = 100009;
const int mod = 1000000007;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector< int > p(n), pos(n);
    for(int i = 0; i < n; ++i) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    ll ans = 1ll;
    int l, r;
    l = r = pos[0];
    for(int i = 1; i < n; ++i) {
      int pi = pos[i];
      if(pi > l && pi < r) {
        ans *= ll(r - l + 1 - i);
        ans %= mod;
      }
      else if(pi < l) l = pi;
      else r = pi;
    }
    cout << ans << endl;
  }
}
