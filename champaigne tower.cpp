#include <stdio.h>

int main() {
    int poured, query_row, query_glass;

    printf("Enter poured, query_row and query_glass: ");
    scanf("%d %d %d", &poured, &query_row, &query_glass);

    double dp[101][101] = {0};

    dp[0][0] = poured;

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j <= i; j++) {

            if(dp[i][j] > 1.0) {

                double excess = (dp[i][j] - 1.0) / 2.0;

                dp[i + 1][j] += excess;
                dp[i + 1][j + 1] += excess;

                dp[i][j] = 1.0;
            }
        }
    }

    if(dp[query_row][query_glass] > 1.0)
        dp[query_row][query_glass] = 1.0;

    printf("%.5f\n", dp[query_row][query_glass]);

    return 0;
}