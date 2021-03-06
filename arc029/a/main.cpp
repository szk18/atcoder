#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

int gcd(int a, int b) {
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

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  int sum = accumulate(t.begin(), t.end(), 0);

  int ans = 999999;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int a = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        a += t[i];
      }
    }
    int tmp = max(a, sum - a);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
