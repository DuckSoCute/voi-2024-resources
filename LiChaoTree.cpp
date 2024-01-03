// Thien linh linh owo dia linh linh xin dung WA cho AC di ma
#include <bits/stdc++.h>
#define getbit(i, j) ((i >> (j)) & 1)
#define cntbit(x) __builtin_popcountll(x)
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define fi first
#define se second
#define _left (id * 2)
#define _right (id * 2 + 1)
#define _lower(v, x) lower_bound(all(v), x)
#define _upper(v, x) upper_bound(all(v), x)

#define VietWasHere "khongon"

using namespace std;

const ll INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9 + 7;

ll sqr(ll x) { return x * x; }
ll power(ll base, ll exp)
{
	ll res = 1;

	for (; exp; exp /= 2, (base *= base) %= MOD)
		if (exp & 1) (res *= base) %= MOD;

	return res;
}

template <typename T> void mini(T &a, T b) { if (b < a) a = b; }
template <typename T> void maxi(T &a, T b) { if (b > a) a = b; }

/* Li Chao Tree - Start */
typedef pair<int, ll> line;

ll f(line l, int x)
{
	return 1ll * l.fi * x + l.se;
}

const int mxn = 200005;
const int mxh = 1000006;

const int H = 1000000;

line T[4 * mxh];

void build(int id = 1, int l = 1, int r = H)
{
	T[id] = {INF, INFLL};
	if (r - l <= 1) return;

	int m = (l + r) / 2;

	build(_left, l, m);
	build(_right, m, r);
}

void add_line(line nw, int id = 1, int l = 1, int r = H)
{
	if (f(nw, l) >= f(T[id], l) && f(nw, r) >= f(T[id], r)) return;
	if (f(nw, l) <= f(T[id], l) && f(nw, r) <= f(T[id], r))
	{
		swap(nw, T[id]);
		return;
	}

	int m = (l + r) / 2;

	bool lef = f(nw, l) < f(T[id], l);
	bool mid = f(nw, m) < f(T[id], m);

	if (mid) swap(T[id], nw);

	if (r - l <= 1) return;

	((lef != mid) ? add_line(nw, _left, l, m) : add_line(nw, _right, m, r));
}

ll get(int x, int id = 1, int l = 1, int r = H)
{
	int m = (l + r) / 2;
	if (r - l <= 1) return f(T[id], x);
	return min(f(T[id], x) , (x <= m) ? get(x, _left, l, m) : get(x, _right, m, r));
}
/* Li Chao Tree - End */

/// Usage
int n, h[mxn];
ll C, dp[mxn];

void solve() // Remember to print result with '\n'
{
	cin >> n >> C;
	for(int i = 1; i <= n; i++) cin >> h[i];
	build();
	dp[1] = 0;
	add_line({-2 * h[1], sqr(h[1]) + dp[1]});

	for(int i = 2; i <= n; i++)
	{
		dp[i] = get(h[i]) + C + sqr(h[i]);
		add_line({-2 * h[i], sqr(h[i]) + dp[i]});
	}

	cout << dp[n] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	if (fopen(VietWasHere".inp", "r"))
	{
		freopen(VietWasHere".inp", "r", stdin);
		freopen(VietWasHere".out", "w", stdout);
	}

	int T = 1;
//	cin >> T;
	while (T--) solve();

	return 0;
}
