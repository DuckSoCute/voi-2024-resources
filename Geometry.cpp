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

struct Point
{
    double x, y;
    Point() { x = y = 0.0; }
    Point(double x, double y): x(x), y(y) {}
};

struct Vector
{
    double x, y;
    Vector(double x, double y): x(x), y(y) {}
    Vector(Point A, Point B): x(B.x - A.x), y(B.y - A.y) {} // AB
};

double cross(Vector AB, Vector AC)
{
	return AB.x * AC.y - AC.x * AB.y;
}

int ccw(Point A, Point B, Point C)
{
	Vector AB(A, B), AC(A, C);
	double res = cross(AB, AC);

	if (res == 0.0) return 0;
	if (res > 0) return 1;
	else return -1;
}

double area(vector<Point> P)
{
	assert(P.size() > 2);
	int END = P.size() - 1;

	double res = 0.0;

	res += cross(Vector(P[0], P[1]), Vector(P[0], P[END]));
	res += cross(Vector(P[END], P[END - 1]), Vector(P[END], P[0]));
	for(int i = 1; i < END; i++) res += cross(Vector(P[i], P[i - 1]), Vector(P[i], P[i + 1]));

	return abs(res) / 2;
}

/// Notes: This code is not well tested

void solve() // Remember to print result with '\n'
{

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
