#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int board[m][n];
    int next[m][n];

    printf("Enter the board:\n");

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            int live = 0;

            for(int r = -1; r <= 1; r++) {
                for(int c = -1; c <= 1; c++) {

                    if(r == 0 && c == 0)
                        continue;

                    int nr = i + r;
                    int nc = j + c;

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       board[nr][nc] == 1)
                        live++;
                }
            }

            if(board[i][j] == 1) {

                if(live < 2)
                    next[i][j] = 0;

                else if(live == 2 || live == 3)
                    next[i][j] = 1;

                else
                    next[i][j] = 0;
            }
            else {

                if(live == 3)
                    next[i][j] = 1;
                else
                    next[i][j] = 0;
            }
        }
    }

    printf("Next State:\n");

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", next[i][j]);
        }
        printf("\n");
    }

    return 0;
}