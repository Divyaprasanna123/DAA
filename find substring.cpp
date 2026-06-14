#include <stdio.h>
#include <string.h>
int main() {
    char haystack[100], needle[100];
    printf("Enter haystack: ");
    scanf("%s", haystack);
    printf("Enter needle: ");
    scanf("%s", needle);
    int n = strlen(haystack);
    int m = strlen(needle);
    int found = -1;
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(haystack[i + j] != needle[j])
                break;
        }
        if(j == m) {
            found = i;
            break;
        }
    }
    printf("%d\n", found);
    return 0;
}