#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    int stations = 3;

    int line1[] = {5, 9, 3};
    int line2[] = {6, 8, 4};
    int line3[] = {7, 6, 5};

    int transfer[3][3] = {
        {0, 2, 3},
        {2, 0, 4},
        {3, 4, 0}
    };

    int dp[3][3];

    dp[0][0] = line1[0];
    dp[1][0] = line2[0];
    dp[2][0] = line3[0];

    for(int j = 1; j < stations; j++) {

        dp[0][j] = line1[j] +
            min(
                min(dp[0][j-1] + transfer[0][0],
                    dp[1][j-1] + transfer[1][0]),
                dp[2][j-1] + transfer[2][0]
            );

        dp[1][j] = line2[j] +
            min(
                min(dp[0][j-1] + transfer[0][1],
                    dp[1][j-1] + transfer[1][1]),
                dp[2][j-1] + transfer[2][1]
            );

        dp[2][j] = line3[j] +
            min(
                min(dp[0][j-1] + transfer[0][2],
                    dp[1][j-1] + transfer[1][2]),
                dp[2][j-1] + transfer[2][2]
            );
    }

    int answer = min(
                    min(dp[0][stations-1],
                        dp[1][stations-1]),
                    dp[2][stations-1]
                 );

    printf("Minimum Production Time = %d\n", answer);

    return 0;
}