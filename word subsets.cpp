#include <stdio.h>
#include <string.h>

void countFreq(char str[], int freq[])
{
    for(int i = 0; i < 26; i++)
        freq[i] = 0;

    for(int i = 0; str[i]; i++)
        freq[str[i] - 'a']++;
}

int main()
{
    int n1, n2;

    scanf("%d", &n1);

    char words1[50][50];

    for(int i = 0; i < n1; i++)
        scanf("%s", words1[i]);

    scanf("%d", &n2);

    char words2[50][50];

    for(int i = 0; i < n2; i++)
        scanf("%s", words2[i]);

    int maxFreq[26] = {0};

    for(int i = 0; i < n2; i++)
    {
        int freq[26];

        countFreq(words2[i], freq);

        for(int j = 0; j < 26; j++)
        {
            if(freq[j] > maxFreq[j])
                maxFreq[j] = freq[j];
        }
    }

    printf("Universal Strings:\n");

    for(int i = 0; i < n1; i++)
    {
        int freq[26];
        countFreq(words1[i], freq);

        int ok = 1;

        for(int j = 0; j < 26; j++)
        {
            if(freq[j] < maxFreq[j])
            {
                ok = 0;
                break;
            }
        }

        if(ok)
            printf("%s\n", words1[i]);
    }

    return 0;
}