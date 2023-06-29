#include <bits/stdc++.h>
using namespace std;
int minImpossibleOR(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int x = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < x) continue;
        if (nums[i] != x) return x;
        x += nums[i];
    }
    return x;
}
int mcinImpossibleOR(vector<int>& nums) {
        map<int, int> mp;
        for (auto& x: nums) {
            mp[x]++;
        }
        for (int i = 0; i < 31; i++) {
            if (!mp[1 << i]) {
                return 1 << i;
            }
        }
        return -1;
    }
int main()
{
    return 0;
}