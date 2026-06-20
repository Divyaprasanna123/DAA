#include <stdio.h>
#include <string.h>

char dict[][20]={
"i","like","sam","sung","samsung",
"mobile","ice","cream","icecream",
"man","go","mango"
};

int dictSize=12;

int wordBreak(char str[])
{
    int len=strlen(str);

    if(len==0)
        return 1;

    for(int i=1;i<=len;i++)
    {
        char prefix[100];

        strncpy(prefix,str,i);
        prefix[i]='\0';

        for(int j=0;j<dictSize;j++)
        {
            if(strcmp(prefix,dict[j])==0)
            {
                if(wordBreak(str+i))
                    return 1;
            }
        }
    }

    return 0;
}

int main()
{
    char str[100];

    scanf("%s",str);

    if(wordBreak(str))
        printf("Yes");
    else
        printf("No");

    return 0;
}