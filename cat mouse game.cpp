#include <stdio.h>

int main()
{
    int result;

    printf("Enter Result (0=Draw, 1=Mouse Wins, 2=Cat Wins): ");
    scanf("%d",&result);

    if(result==0)
        printf("Draw");
    else if(result==1)
        printf("Mouse Wins");
    else
        printf("Cat Wins");

    return 0;
}