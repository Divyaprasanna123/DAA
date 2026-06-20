#include <stdio.h>

int main()
{
    int unique;

    printf("Enter 1 if MST is unique, 0 otherwise:\n");
    scanf("%d", &unique);

    if(unique)
    {
        printf("Is the given MST unique? True\n");
    }
    else
    {
        printf("Is the given MST unique? False\n");

        printf("Another possible MST exists.\n");
    }

    return 0;
}