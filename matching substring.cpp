#include <stdio.h>
#include <string.h>
int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);
    char words[n][100];
    printf("Enter words:\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    printf("Substrings found:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && strstr(words[j], words[i]) != NULL) {
                printf("%s\n", words[i]);
                break;
            }

        }
    }
    return 0;
}