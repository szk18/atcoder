#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    dfs(G, next);
  }
}

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

vector<ll> divisors(ll n) {
  vector<ll> a;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      if (n / i != i) a.push_back(n / i);
    }
  }
  sort(a.begin(), a.end());
  return a;
}

// pairを要素に持つvectorをsecondを基準にソートする比較関数
bool comp(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }

int main() {
  ll n, X;
  cin >> n >> X;
  vector<ll> x(n + 1);
  rep(i, n) cin >> x[i];
  x[n] = X;
  sort(x.begin(), x.end());

  vector<ll> w(n);
  rep(i, n) { w[i] = abs(x[i] - x[i + 1]); }

  ll ans = w[0];
  rep(i, n) { ans = gcd(ans, w[i]); }
  cout << ans << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
