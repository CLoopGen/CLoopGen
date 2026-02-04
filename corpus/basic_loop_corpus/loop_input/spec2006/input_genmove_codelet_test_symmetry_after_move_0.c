#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 1000;
Intersection board[421];
int pos;
int result;

void init_vars() {
    board_size = 20; // Set board_size to 20 to satisfy loop bounds
    
    // Initialize the board array with a checkerboard pattern to ensure defined behavior
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 2) ? 1 : 0;
    }

    pos = 0;
    result = 1; // Default success unless mismatch found
}