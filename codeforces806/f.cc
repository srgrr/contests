#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    vector< int > v(n);

    for(int& x: v) {
      scanf("%d", &x);
    }

    multiset< int > more;
    int cnt = 0;
    ll ans = 0ll;

    for(int i = n; i > 0; --i) {

      while(more.size() > 0 && -(*more.begin()) > i) {
        ++cnt;
        more.erase(more.begin());
      }

      if(v[i - 1] < i) {
        ans += ll(cnt);
        more.insert(-v[i - 1]);
      }
    }

    printf("%lld\n", ans);
  }
}
