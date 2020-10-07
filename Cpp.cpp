#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(v) (v).begin(), (v).end()

template <typename T>
T power(T x, T y, T n)
{
    x %= n;
    T ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = ans * x % n;
        }
        x = x * x % n;
        y >>= 1;
    }
    return (ans);
}

template <typename T>
bool check_composite(T n, T a, T d, T s)
{
    // it returns 0 if n is composite else returns 1
    T x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return 0;
    for (int i = 0; i < s - 1; i++)
    {
        x = x * x % n;
        if (x == n - 1)
            return 0;
    }
    return 1;
}

template <typename T>
bool is_prime(T n)
{
    // it returns 1 if n is prime
    if (n == 2 || n == 3)
        return 1;
    T s = 0, d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return 1;
        if (check_composite(n, a, d, s))
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
