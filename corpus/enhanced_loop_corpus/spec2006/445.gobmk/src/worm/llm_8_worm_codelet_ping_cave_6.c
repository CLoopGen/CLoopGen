#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int BOARD_SIZE = 19;
    const int TOTAL_CELLS = (BOARD_SIZE + 1) * (BOARD_SIZE + 1);
    const int OFFSET = BOARD_SIZE + 1;
    int p;

    for (p = BOARD_SIZE + 2; p < TOTAL_CELLS; p += 2)
        if (board[p] != 3 && mse[p]) {
            int up = p + OFFSET, down = p - OFFSET;
            int left = p - 1, right = p + 1;
            int cond1 = (!(board[up] != 3) || board[up] == other) && (!(board[down] != 3) || board[down] == other);
            int cond2 = (!(board[left] != 3) || board[left] == other) && (!(board[right] != 3) || board[right] == other);
            if (cond1 || cond2)
                mse[p] = 0;
        }
}
