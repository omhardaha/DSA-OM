#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=utZcJ0leZ_g&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=64
// Greatest Commom Divisor ----->
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b); //log(n)
}
int LCM(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
int main()
{
    // Inbuit Function -
    int gcdNum = __gcd(13, 39);
    
    return 0;
}