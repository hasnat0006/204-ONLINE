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

vector<int> creating_lps(string &pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[index] == pattern[i])
        {
            lps[i] = index + 1;
            index++, i++;
        }
        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, i++;
        }
    }
    return lps;
}

void kmp(string &text, string &pattern)
{
    vector<int> lps = creating_lps(pattern);
    for (auto t : lps)
        cout << t << " ";
    cout << endl;
    dbg(lps);
    int i = 0, j = 0;
    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pattern.length())
        {
            cout << "Pattern match!\n";
            j = lps[j - 1];
            i++;
        }
    }
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;
    kmp(text, pattern);
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