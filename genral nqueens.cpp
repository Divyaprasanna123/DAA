#include <stdio.h>
#include <stdlib.h>

int board[20];

int isSafe(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i]==col ||
           abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

int solve(int row,int n)
{
    if(row==n)
        return 1;

    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col))
        {
            board[row]=col;

            if(solve(row+1,n))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n;

    scanf("%d",&n);

    if(solve(0,n))
    {
        for(int i=0;i<n;i++)
            printf("%d ",board[i]+1);
    }
    else
    {
        printf("No Solution");
    }

    return 0;
}