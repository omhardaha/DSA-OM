#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

int power(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    long long result = power(a, b / 2);
    if (b & 1)
    {
        return (a * ((result * 1LL * result) % M)) % M;
    }
    return (result * 1LL * result) % M;
}
int powerterative(int a, int b)
{
    long long result = a;
    while (b)
    {
        if (b & 1)
        {
            result = (result * result * 1LL) % M;
        }
        a = (a * a * 1LL) % M;
        b >>= 1;
    }
    return result;
}

int main()
{
    cout << power(34, 34634);
    // cout << powerterative(34, 34634);
    return 0;
}