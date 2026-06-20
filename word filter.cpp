#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    char words[n][100];

    for(int i=0;i<n;i++)
        scanf("%s",words[i]);

    char pref[100],suff[100];

    scanf("%s",pref);
    scanf("%s",suff);

    int ans=-1;

    for(int i=0;i<n;i++)
    {
        int len=strlen(words[i]);
        int pLen=strlen(pref);
        int sLen=strlen(suff);

        if(strncmp(words[i],pref,pLen)==0 &&
           strcmp(words[i]+len-sLen,suff)==0)
            ans=i;
    }

    printf("%d",ans);

    return 0;
}