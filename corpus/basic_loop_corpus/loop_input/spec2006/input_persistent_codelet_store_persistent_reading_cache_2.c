#include <stdio.h>
#include <inttypes.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
char active[400];
int k;

void init_vars() {
    const int N = 19 + 1;
    const int BOARD_SIZE = N * N; 

    memset(board, 0, sizeof(board));
    memset(active, 0, sizeof(active));

    for (int i = 0; i < 400; i++) {
        if (i % 7 == 0) {
            board[i] = 1;
        } else if (i % 13 == 0) {
            board[i] = 2;
        }
        
        if (i % 17 == 0) {
            active[i] = 2;
        }
    }

    for (int i = N; i < BOARD_SIZE - N; i++) {
        if (i >= N && i < 400 - N) {
            if (active[i + N] == 2 || active[i - 1] == 2 || 
                active[i - N] == 2 || active[i + 1] == 2) {
                if (board[i] == 0 && active[i] == 0) {
                    active[i] = 0;
                }
            }
        }
    }
}