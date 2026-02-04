#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx, row, col;
    for (k = 0; k < ((19 + 2) * (19 + 1) + 1); k += 2) {
        idx = k;
        row = idx / (19 + 1) - 1;
        col = idx % (19 + 1) - 1;
        if (!((unsigned int)(row) < (unsigned int)board_size && (unsigned int)(col) < (unsigned int)board_size)) {
            board[idx] = 3;
            initial_board[idx] = 3;
        }
        if (k + 1 < ((19 + 2) * (19 + 1) + 1)) {
            idx = k + 1;
            row = idx / (19 + 1) - 1;
            col = idx % (19 + 1) - 1;
            if (!((unsigned int)(row) < (unsigned int)board_size && (unsigned int)(col) < (unsigned int)board_size)) {
                board[idx] = 3;
                initial_board[idx] = 3;
            }
        }
    }
}
