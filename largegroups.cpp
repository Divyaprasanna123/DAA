#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);
    int n = strlen(s);
    printf("[");
    int first = 1;
    for(int i = 0; i < n; ) {
        int start = i;
        while(i < n && s[i] == s[start]) {
            i++;
        }
        int end = i - 1;
        if(end - start + 1 >= 3) {
            if(!first)
                printf(",");

            printf("[%d,%d]", start, end);
            first = 0;
        }
    }
    printf("]");
    return 0;
}