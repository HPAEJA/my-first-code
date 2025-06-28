#include <stdio.h>

int main() {
    int weight[] = {2, 3, 4, 5};
    int value[] = {3, 4, 5, 6};
    int n = 4;
    int capacity = 5;

    int i, w;

    int dp[10][10]; // dp[i][w] will store max value for first i items and capacity w

    // Build the dp table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // base case: no items or capacity 0
            } else if (weight[i - 1] <= w) {
                // Include or exclude the item
                int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                // Can't include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum value in knapsack = %d\n", dp[n][capacity]);
    return 0;
}

