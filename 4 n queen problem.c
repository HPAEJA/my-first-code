#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 4;  // You can change this to solve for other N
    int board[10];  // board[i] stores the column position of queen in row i
    int i, j, row, valid;

    for (i = 1; i <= n; i++) {
        board[i] = 0;  // initialize the board
    }

    row = 1;  // start from the first row

    while (row > 0) {
        board[row]++;

        while (board[row] <= n) {
            valid = 1;
            for (i = 1; i < row; i++) {
                if (board[i] == board[row] || abs(board[i] - board[row]) == abs(i - row)) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                break;
            } else {
                board[row]++;
            }
        }

        if (board[row] <= n) {
            if (row == n) {
                printf("Solution:\n");
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        if (board[i] == j) {
                            printf("Q ");
                        } else {
                            printf(". ");
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            } else {
                row++;
                board[row] = 0;
            }
        } else {
            row--;
        }
    }

    return 0;
}

