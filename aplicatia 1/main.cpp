#include <iostream>

using namespace std;

/// Produsul elementelor impare din vector

int n, a[105];

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

int produs (int s, int d)
{
    if (s == d)
    {
        if (a[s] % 2 == 1)
            return a[s];
        return 1;
    }
    int m = (s + d) / 2;
    return produs (s, m) * produs(m + 1, d);
}

int main()
{
    cin >> n;
    citire(0, n - 1);
    cout << produs(0, n - 1);
    return 0;
}
