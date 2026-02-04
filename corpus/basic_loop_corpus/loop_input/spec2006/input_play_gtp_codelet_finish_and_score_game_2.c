#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
int final_status[19][19];
int i;
int j;
int saved_board[19][19];

void init_vars() {
    // Initialize board to size (19+2) + i*(19+1) + j indexing pattern
    // The indexing used is: board[(19 + 2) + i * (19 + 1) + j]
    // Max index: (19+2) + 18*(19+1) + 18 = 21 + 360 + 18 = 399, so we need at least 400 elements
    memset(board, 0, sizeof(board));

    // Fill valid region of board with non-uniform data
    for (int idx = 19 + 2; idx < 400; idx++) {
        board[idx] = (unsigned char)(idx % 3); // values 0, 1, 2
    }

    // Initialize final_status and saved_board within bounds [0..18][0..18]
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            final_status[i][j] = rand() % 16; // 0 to 15
            saved_board[i][j] = rand() % 3;   // 0, 1, 2
        }
    }

    // Ensure loop variables are initialized
    i = 0;
    j = 0;
}