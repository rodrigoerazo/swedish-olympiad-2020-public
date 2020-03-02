#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll clamp(ll x, ll a, ll b) {
  if(x < a) x = a;
  if(x > b) x = b;
  return x;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, q, H, W;
  cin>>n>>q>>H>>W;
  W += 5;
  vector<ll> up(W,H), down(W,0);
  rep(i,0,n) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) down[x] = y;
    if(t == 2) up[x] = y;
  }

  rep(i,0,q) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2) swap(x1,x2), swap(y1,y2);
    ll h = y1, ans = x2-x1;
    for(int x = x1; x != x2; ++x) {
      ll hh = clamp(h, down[x], up[x]);
      ans += abs(hh-h);
      h = hh;
    }
    {
      ll hh = clamp(h, y2, y2);
      ans += abs(hh-h);
      h = hh;
    }
    cout << ans << endl;
  }
}