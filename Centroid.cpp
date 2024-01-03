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

const int mxn = 100005;

int n, m, par[mxn];
int h[mxn], cha[29][mxn];
int sz[mxn];
vector<int> vt[mxn];
multiset<int> kc[mxn];
bool mark[mxn];

void dfs(int u)
{
    for(int v : vt[u])
    {
        if (v == cha[0][u]) continue;

        h[v] = h[u] + 1;
        cha[0][v] = u;
        for(int j = 1; j <= 19; j++) cha[j][v] = cha[j - 1][cha[j - 1][v]];

        dfs(v);
    }
}

int lca(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);

    int kc = h[v] - h[u];
    for(int i = 0; i <= 19; i++)
        if (getbit(kc, i)) v = cha[i][v];

    if (u != v)
    {
        for(int i = 19; i >= 0; i--)
        {
            if (cha[i][u] == cha[i][v]) continue;

            u = cha[i][u];
            v = cha[i][v];
        }

        u = cha[0][u];
    }

    return u;
}

int dist(int u, int v)
{
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void calcSize(int u, int parent)
{
    sz[u] = 1;

    for(int v : vt[u])
    {
        if (v == parent || par[v]) continue;
        calcSize(v, u);
        sz[u] += sz[v];
    }
}

int getCentroid(int u, int parent, int rr)
{
    for(int v : vt[u])
        if (v != parent && !par[v] && sz[v] > (sz[rr] / 2)) return getCentroid(v, u, rr);
    return u;
}

void decompose(int u, int parent)
{
    calcSize(u, parent);

    int centroid = getCentroid(u, parent, u);
    par[centroid] = (parent ? parent : centroid);

    for(int v : vt[centroid])
    {
        if (par[v]) continue;
        decompose(v, centroid);
    }
}

void solve() // Remember to print result with '\n'
{
	cin >> n;
    for(int _ = 1; _ < n; _++)
    {
        int u, v;
        cin >> u >> v;

        vt[u].pb(v);
        vt[v].pb(u);
    }

    decompose(1, 0);
    dfs(1);

    cin >> m;
    for(int _ = 1; _ <= m; _++)
    {
        int t, u;
        cin >> t >> u;

        if (t == 1)
        {
            mark[u] = !mark[u];

            int v = u;

            if (mark[u])
            {
                while(v != par[v])
                {
                    kc[v].insert(dist(v, u));
                    v = par[v];
                }

                kc[v].insert(dist(v, u));
            }
            else
            {
                while(v != par[v])
                {
                    kc[v].erase(kc[v].find(dist(v, u)));
                    v = par[v];
                }

                kc[v].erase(kc[v].find(dist(v, u)));
            }
        }
        else
        {
            int res = INF, v = u;

            while(v != par[v])
            {
                if (sz(kc[v])) res = min(res, dist(u, v) + *kc[v].begin());
                v = par[v];
            }

            if (sz(kc[v])) res = min(res, dist(u, v) + *kc[v].begin());

            cout << ((res < INF) ? res : -1) << '\n';
        }
    }
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
