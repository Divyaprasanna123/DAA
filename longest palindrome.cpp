#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    printf("Enter string: ");
    scanf("%s", s);
    int n = strlen(s);
    int start = 0, maxLen = 1;
    for(int i = 0; i < n; i++) {
     int left = i, right = i;
        while(left >= 0 && right < n &&
              s[left] == s[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
     left = i;
        right = i + 1;
        while(left >= 0 && right < n &&
              s[left] == s[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
    printf("Longest Palindromic Substring: ");
    for(int i = start; i < start + maxLen; i++)
        printf("%c", s[i]);
    return 0;
}