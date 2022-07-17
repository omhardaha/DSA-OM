#include <bits/stdc++.h>
using namespace std;

int MCM_Memoization(vector<int> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    for (int k = i; k < j; k++)
    {
        int cur = MCM_Memoization(matrix, i, k, dp) + MCM_Memoization(matrix, k + 1, j, dp) + matrix[i - 1] * matrix[k] * matrix[j];
        ans = min(ans, cur);
    }
    return dp[i][j] = ans;
}

int MCM_Tabulation(vector<int> &matrix)
{
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, 0));
    for (int i = matrix.size() - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < matrix.size(); j++)
        {
            int ans = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cur = dp[i][k] + dp[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j];
                ans = min(ans, cur);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][matrix.size() - 1];
}

int main()
{
    vector<int> matrix = {40, 20, 30, 10, 30};
    // vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
    // cout << MCM_Tabulation(matrix);
    return 0;
}