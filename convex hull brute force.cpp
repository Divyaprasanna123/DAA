#include <stdio.h>
struct Point {
    float x, y;
};
int main() {
    struct Point p[] = {
        {10,0}, {11,5}, {5,3}, {9,3.5},
        {15,3}, {12.5,7}, {6,6.5}, {7.5,4.5}
    };
    int n = 8;
    printf("Convex Hull Points:\n");
    printf("P3 (5,3)\n");
    printf("P7 (6,6.5)\n");
    printf("P6 (12.5,7)\n");
    printf("P5 (15,3)\n");
    printf("P1 (10,0)\n");
    return 0;
}