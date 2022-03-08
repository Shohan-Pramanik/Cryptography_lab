#include <bits/stdc++.h>
using namespace std;

long long Bigmod(long long b, long long p, long long m)
{
    long long res = 1;
    for(long long i = 1; i<=p; i++)
    {
        res *= b;
        res %= m;
    }
    return res;
}

bool IsPrime(int p, int iter)
{
    if(p == 1) return false;
    if(p == 2 || p == 3) return true;
    if(p % 2 == 0) return false;

    for(int i=0; i<iter; i++)
    {
        int a = 2 + (rand() % (p-3));
        int L = Bigmod(a, (p-1)/2, p); //a^((p-1)/2) % p
        if(L != 1 && L != -1 && L != (p-1)) return false;
    }

    return true;
}

int main()
{
    int n = 9767;
    if(IsPrime(n,100))
    {
        cout<<"Prime\n";
    }
    else
    {
        cout<<"Not Prime\n";
    }
    return 0;
}
