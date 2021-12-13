#include <iostream>

using namespace std;

/// Cmmmc al elementelor vectorului

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

int cmmdc (int a, int b)
{
    if (!b)
        return a;
    return cmmdc(b, a%b);
}

int cmmdc_vect (int s, int d)
{
    if (s == d)
        return a[s];
    int m = (s + d) / 2;
    int cms = cmmdc_vect(s, m);
    int cmd = cmmdc_vect(m + 1, d);
    return cmmdc(cms, cmd);
}

int main()
{
    cin >> n;
    citire(0, n - 1);
    cout << "CMMDC vector: " << cmmdc_vect(0, n - 1);
    return 0;
}
