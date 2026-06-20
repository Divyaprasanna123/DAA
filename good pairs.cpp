#include <stdio.h>

int main()
{
    int n;

    scanf("%d",&n);

    int nums[n];

    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    int count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]==nums[j])
                count++;
        }
    }

    printf("%d",count);

    return 0;
}