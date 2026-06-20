#include <stdio.h>
#include <stdlib.h>

int board[20];

int isSafe(int row, int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i]==col ||
           abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void printBoard(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i]==j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int solve(int row,int n)
{
    if(row==n)
    {
        printBoard(n);
        return 1;
    }

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

    if(!solve(0,n))
        printf("No Solution");

    return 0;
}