#include <iostream>

using namespace std;

/// Maximul și minimul din vector transmise ca parametru într-o singură funcție.

int a[105], n;

void citire (int s, int d)
{
    if (s == d)
    {
        cin >> a[s];
        return;
    }
    int m = (s + d) / 2;
    citire(s, m);
    citire(m + 1, d);
}

void min_max (int s, int d, int &vmin, int &vmax)
{
    int mins, mind, maxs, maxd;
    if (s == d)
    {
        vmin = a[s];
        vmax = a[s];
        return;
    }
    int m =(s + d)/2;
    min_max(s, m, mins, maxs);
    min_max(m + 1, d, mind, maxd);
    if (mins < mind)
        vmin = mins;
    else
        vmin = mind;
    if (maxs > maxd)
        vmax = maxs;
    else
        vmax = maxd;
}

int main()
{
    cin >> n;
    citire(0, n - 1);
    int vmax = INT_MAX, vmin = INT_MIN;
    min_max(0, n - 1, vmin, vmax);
    cout << vmax << " " << vmin;
    return 0;
}
