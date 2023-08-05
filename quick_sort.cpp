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

int partion(int low, int high, vector<int> &v)
{
    int pivot = v[low];
    int i = low, j = high;
    while (i < j)
    {
        while (v[i] <= pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i < j)
            swap(v[i], v[j]);
        dbgc("In part ", v);
    }
    swap(v[low], v[j]);
    return j;
}

void quick_sort(int low, int high, vector<int> &v)
{
    if (low < high)
    {
        int j = partion(low, high, v);
        if (is_sorted(vf(v)))
            return;
        quick_sort(low, j - 1, v);
        dbg("In sort", v);
        quick_sort(j + 1, high, v);
        dbg(v);
    }
    else
        return;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    quick_sort(0, n - 1, v);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}