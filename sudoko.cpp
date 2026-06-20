#include <stdio.h>

int board[9][9];

int isSafe(int row,int col,int num)
{
    for(int x=0;x<9;x++)
        if(board[row][x]==num)
            return 0;

    for(int x=0;x<9;x++)
        if(board[x][col]==num)
            return 0;

    int sr=row-row%3;
    int sc=col-col%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[sr+i][sc+j]==num)
                return 0;

    return 1;
}

int solve()
{
    int row,col,found=0;

    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(board[row][col]==0)
            {
                found=1;
                goto END;
            }
        }
    }

END:

    if(!found)
        return 1;

    for(int num=1;num<=9;num++)
    {
        if(isSafe(row,col,num))
        {
            board[row][col]=num;

            if(solve())
                return 1;

            board[row][col]=0;
        }
    }

    return 0;
}

int main()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            scanf("%d",&board[i][j]);

    solve();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            printf("%d ",board[i][j]);

        printf("\n");
    }

    return 0;
}