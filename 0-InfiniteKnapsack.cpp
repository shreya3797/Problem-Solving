int knapsack(vector<int> &A, vector<int> &B, vector<vector<int>> &dp, int N, int W) {
    if (N == 0) return 0;
    if (W == 0) return 0;
    if (dp[N][W] == -1) {
        if (B[N-1] <= W) {
            dp[N][W] = max(knapsack(A, B, dp, N-1, W), A[N-1] + knapsack(A, B, dp, N, W-B[N-1]));
        } else {
            dp[N][W] = knapsack(A, B, dp, N-1, W);
        }
    }
    return dp[N][W];
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<vector<int>> dp(n+1, vector<int>(A+1, -1));
    return knapsack(B, C, dp, n, A);
}
