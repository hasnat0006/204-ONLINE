//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

const int N = 1000;
vector<int> v(N), tree(4 * N);

void Segment_tree(int i, int j, int ti)
{
    dbg(i, j, ti);
    if (i == j)
    {
        tree[ti] = v[i];
        return;
    }
    int mid = (i + j) / 2;
    // dbg(mid);
    Segment_tree(i, mid, 2 * ti + 1);
    Segment_tree(mid + 1, j, 2 * ti + 2);
    tree[ti] = tree[2 * ti + 1] + tree[2 * ti + 2];
}

int find(int ql, int qr, int tl, int tr, int ti)
{
    dbg(tl, tr, ti);
    if (ql > tr or qr < tl)
        return 0;
    if (ql <= tl and qr >= tr)
        return tree[ti];
    int mid = (tr + tl) / 2;
    int L = find(ql, qr, tl, mid, 2 * ti + 1);
    int R = find(ql, qr, mid + 1, tr, 2 * ti + 2);
    return L + R;
}

void update(int l, int r, int id, int val, int ti)
{
    dbg(l, r, ti);
    if (id > r or id < l)
        return;
    if (id == r and id == l)
    {
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, id, val, 2 * ti + 1);
    update(mid + 1, r, id, val, 2 * ti + 2);
    tree[ti] = tree[2 * ti + 1] + tree[2 * ti + 2];
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Segment_tree(0, n - 1, 0);
    int q, l, r;
    cin >> q;
    while (q--)
    {
        dbg("---QUERY---");
        cin >> l >> r;
        cout << find(l, r, 0, n - 1, 0) << endl;
    }
    dbg("---UPDATE---");
    update(0, n - 1, 3, 15, 0);
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}