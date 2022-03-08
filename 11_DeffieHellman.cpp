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
    return res%m;
}

int main()
{
    srand(time(NULL));

    long long q = 13; //Random Prime
    long long a = 2; //Premitive Root
    long long Xa = 1 + (rand() % 100); //Alice's Private Key
    long long Xb = 1 + (rand() % 100); //Bob's Private Key

    long long Ya = Bigmod(a, Xa, q); //Alice's Public Key   (a^Xa)%q
    long long Yb = Bigmod(a, Xb, q); //Bob's Public Key     (a^Xb)%q

    long long Ka = Bigmod(Yb, Xa, q); //Common Key (Yb^Xa)%q
    long long Kb = Bigmod(Ya, Xb, q); //Common Key (Ya^Xb)%q

    cout<<"Common Key, Ka = "<<Ka<<endl;
    cout<<"Common Key, Kb = "<<Kb<<endl;

    return 0;
}
