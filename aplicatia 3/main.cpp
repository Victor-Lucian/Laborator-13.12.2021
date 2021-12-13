#include <iostream>

using namespace std;

/// verif daca toate elementele din vector au cif impare ordonate descrescator

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

int prop (int x, int y)
{
    if (x == 0)
        return 1;
    if ((x % 10) % 2 == 1)
    {
        if (x % 10 < y)
            return 0;
        return prop(x % 10, x / 10);
    }
    return prop (x % 10, y);
}

int verificare (int s, int d)
{
    if (s == d)
        return prop(a[s], 11);
    int m = (s + d) / 2;
    return verificare(s, m) * verificare(m + 1, d);
}

int main()
{
    cin >> n;
    citire(0, n - 1);
    if (verificare(0, n - 1) == 1)
        cout << "Toate au proprietatea";
    else
        cout << "Un numar nu respecta conditia";
    return 0;
}
