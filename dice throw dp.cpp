#include <stdio.h>
int main() {
    int num_sides, num_dice, target;
    printf("Enter number of sides: ");
    scanf("%d", &num_sides);
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter target sum: ");
    scanf("%d", &target);
    int dp[num_dice + 1][target + 1];
   for(int i = 0; i <= num_dice; i++) {
        for(int j = 0; j <= target; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int dice = 1; dice <= num_dice; dice++) {
        for(int sum = 1; sum <= target; sum++) {
            for(int face = 1; face <= num_sides; face++) {
                if(sum - face >= 0) {
                    dp[dice][sum] += dp[dice - 1][sum - face];
                }
            }
        }
    }
    printf("Number of ways to reach sum %d: %d\n",
           target, dp[num_dice][target]);
    return 0;
}