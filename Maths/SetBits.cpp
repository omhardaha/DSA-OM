#include <bits/stdc++.h>
using namespace std;
void setItBit(int ith, int &visited)
{
    int mask = (1 << (ith - 1));
    visited |= mask;
}
void unSetItBit(int ith, int &visited)
{
    int mask = (1 << (ith - 1));
    mask = (~mask);
    visited &= mask;
}

bool checkIthBit(int ith, int &visited)
{
    int mask = visited >> (ith - 1);
    return mask & 1;
}
int main()
{
    int a = 0;
    setItBit(2, a);
    setItBit(1, a);
    setItBit(3, a);
    setItBit(20, a);
    unSetItBit(20, a);
    cout << (1<<21);
    return 0;
}