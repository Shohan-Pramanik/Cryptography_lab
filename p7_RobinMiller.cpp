#include <bits/stdc++.h>
using namespace std;

long long Bigmod(long long b, long long p, long long m)
{
    long long res = 1;
    for (long long i = 1; i <= p; i++)
    {
        res *= b;
        res %= m;
    }
    return res;
}

bool RobinMiller(long long p)
{
    long long m, b;

    // Finding b,m such that, m*(2^b) = p-1
    m = p - 1;
    b = 1;
    while (m % 2 == 0)
    {
        m /= 2;
        b++;
    }

    long long a = 1 + (rand() % (p - 1));
    long long j = 0;
    long long z = Bigmod(a, m, p);
    long long prev;

    while (j < b && z != 1)
    {
        prev = z;
        z *= z;
        z %= p;

        if (z == 1 && (prev != 1 && prev != p - 1))
            return false;

        j++;
    }

    if (z == 1)
        return true;
    else
        return false;
}

bool IsPrime(long long p, long long iter)
{
    if (p == 1)
        return false;
    if (p == 2 || p == 3)
        return true;
    if (p % 2 == 0)
        return false;

    for (long long i = 0; i < iter; i++)
    {
        bool L = RobinMiller(p);
        if (L == false)
            return false;
    }
    return true;
}

int main()
{
    long long n = 60;
    if (IsPrime(n, 100))
    {
        cout << "Prime\n";
    }
    else
    {
        cout << "Not Prime\n";
    }
    return 0;
}
