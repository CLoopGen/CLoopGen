#include <inttypes.h>

int board[144];
int piece_count;
int pieces[62];
int j;
int a;
int i;
int wp;
int bp;

void init_vars() {
    // Initialize board with values that will trigger wp or bp increments
    for (int idx = 0; idx < 144; idx++) {
        if (idx % 2 == 0)
            board[idx] = 1;  // white piece types
        else
            board[idx] = 2;  // black piece types
    }

    // Set up pieces array: ensure it contains valid indices into board
    for (int idx = 0; idx < 62; idx++) {
        pieces[idx] = (idx * 2) % 144;  // valid index within board bounds
    }

    // Set piece_count to full size of pieces array minus one (since we use 1-based indexing in loop)
    piece_count = 61;

    // Initialize loop counters and accumulators
    j = 0;
    a = 0;
    i = 0;
    wp = 0;
    bp = 0;
}