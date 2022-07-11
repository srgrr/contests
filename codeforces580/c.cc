#include <cstdio>
#include <vector>
using namespace std;


int max_rests(
  vector< vector< int > >& g,
  vector< bool >& cat,
  int v,
  int par,
  int cat_count,
  int max_cats) {

  int current_cats = cat[v] ? cat_count + 1 : 0;

  if(current_cats > max_cats) {
    return 0;
  }

  if(g[v].size() == 1 && g[v][0] == par) {
    return 1;
  }

  int ret = 0;

  for(int adj: g[v]) {
    if(adj != par) {
      ret += max_rests(g, cat, adj, v, current_cats, max_cats);
    }
  }

  return ret;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector< vector< int > > g(n, vector< int >());
  vector< bool > cat(n);

  for(int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    cat[i] = x;
  }

  for(int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  printf("%d\n", max_rests(g, cat, 0, -1, 0, m));
}
