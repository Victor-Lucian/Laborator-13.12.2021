#include <iostream>

using namespace std;

/// Să se verifice dacă toate palindromurile sunt la începutul vectorului.

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

int oglindit (int n, int ogl)
{
    if (n == 0)
        return ogl;
    return oglindit(n / 10, ogl * 10 + n % 10);
}

int palindrom (int x)
{
    if (x == oglindit(x, 0))
        return 1;
    return 0;
}

int verificare (int s, int d)
{
    if (s == d)
    {
        if (palindrom(a[s]) == 0 && palindrom(a[s + 1]) == 1)
            return 0;
        return 1;
    }
    int m = (s + d) / 2;
    return verificare(s, m) && verificare(m + 1, d);
}

int main()
{
    cin >> n;
    citire(0, n - 1);
    if (verificare(0, n - 2) == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
