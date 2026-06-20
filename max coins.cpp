#include <stdio.h>

void sort(int piles[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(piles[i] > piles[j])
            {
                temp = piles[i];
                piles[i] = piles[j];
                piles[j] = temp;
            }
        }
    }
}

int maxCoins(int piles[], int n)
{
    sort(piles, n);

    int left = 0;
    int right = n - 1;
    int coins = 0;

    while(left < right)
    {
        right--;               
        coins += piles[right]; // You take second largest
        right--;
        left++;                // Bob takes smallest
    }

    return coins;
}

int main()
{
    int n, i;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter pile values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &piles[i]);
    }

    printf("Maximum coins you can get = %d\n", maxCoins(piles, n));

    return 0;
}