#include <stdio.h>
#include <string.h>
int main() {
    char words[][20] = {"abc", "car", "ada", "racecar", "cool"};
    int n = 5;
    for(int i = 0; i < n; i++) {
        int l = 0, r = strlen(words[i]) - 1;
        int pal = 1;
        while(l < r) {
            if(words[i][l] != words[i][r]) {
                pal = 0;
                break;
            }
            l++;
            r--;
        }
        if(pal) {
            printf("%s", words[i]);
            return 0;
        }
    }
    printf("\"\"");
    return 0;
}