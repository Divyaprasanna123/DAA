#include <stdio.h>
int main() {
    int nums1[] = {2, 3, 2};
    int nums2[] = {1, 2};
    int n = 3, m = 2;
    int answer1 = 0, answer2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums1[i] == nums2[j]) {
                answer1++;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(nums2[i] == nums1[j]) {
                answer2++;
                break;
            }
        }
    }
    printf("[%d,%d]", answer1, answer2);
    return 0;
}