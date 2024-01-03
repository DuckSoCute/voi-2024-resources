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

const int mxn = 1000006;

int n, k;
ll m, f[mxn];

const int N = 2; // Size of matrix

struct Matrix
{
    ll a[N + 1][N + 1];
};

Matrix operator * (Matrix &a, Matrix &b)
{
    Matrix kq;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            kq.a[i][j] = 0;
            for(int t = 1; t <= N; t++)
			{
				ll val = (a.a[i][t] * b.a[t][j]) % k;
				(kq.a[i][j] += val) %= k;
			}
        }

    return kq;
}

Matrix power(Matrix base, ll exp)
{
    Matrix ans;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            ans.a[i][j] = i == j;

    for(; exp; exp /= 2, base = base * base)
        if (exp % 2 == 1) ans = ans * base;

    return ans;
}

/// Usage
ll S[mxn];
int vt[mxn];

void solve() // Remember to print result with '\n'
{
    cin >> n >> m >> k;

    if (m == 1)
    {
        f[0] = 0;
        f[1] = 1;
    }
    else if (m == 2)
    {
        f[0] = 1;
        f[1] = 1;
    }
    else
    {
        Matrix A;
        A.a[1][1] = 1;
        A.a[1][2] = 1;
        A.a[2][1] = 1;
        A.a[2][2] = 0;

        Matrix F = power(A, m - 2);

        f[0] = (F.a[2][1] + F.a[2][2]) % k;
        f[1] = (F.a[1][1] + F.a[1][2]) % k;
    }

    for(int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % k;
//	for(int i = 1; i <= n; i++) cout << f[i] << ' '; cout << '\n';

	S[0] = 0;
	fill(vt, vt + k, 0);
	for(int i = 1; i <= n; i++)
	{
		S[i] = (S[i - 1] + f[i]) % k;

		if (vt[S[i]] || S[i] == 0)
		{
			cout << i - vt[S[i]] << ' ';
			for(int j = vt[S[i]] + 1; j <= i; j++) cout << m + j - 1 << ' ';
			cout << '\n';
			return;
		}

		vt[S[i]] = i;
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
