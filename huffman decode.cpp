#include <stdio.h>
#include <string.h>

int main()
{
    char encoded[1000];

    scanf("%s", encoded);

    int n = strlen(encoded);

    for(int i = 0; i < n; i += 2)
    {
        if(encoded[i] == '0')
            printf("a");
        else
            printf("b");
    }

    return 0;
}