#include <stdio.h>
#include <string.h>

int main()
{
    int n,maxWidth;

    scanf("%d",&n);

    char words[n][50];

    for(int i=0;i<n;i++)
        scanf("%s",words[i]);

    scanf("%d",&maxWidth);

    int i=0;

    while(i<n)
    {
        int len=strlen(words[i]);
        int j=i+1;

        while(j<n &&
             len+1+strlen(words[j])<=maxWidth)
        {
            len+=1+strlen(words[j]);
            j++;
        }

        for(int k=i;k<j;k++)
        {
            printf("%s",words[k]);

            if(k!=j-1)
                printf(" ");
        }

        printf("\n");

        i=j;
    }

    return 0;
}