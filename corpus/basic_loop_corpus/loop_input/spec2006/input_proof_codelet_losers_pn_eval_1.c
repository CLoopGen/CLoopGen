#include <stdint.h>
#include <string.h>

int board[144];
int piece_count;
int pieces[62];
int i;
int j;
int a;
int wp;
int bp;

void init_vars() {
    // Initialize board with values that will trigger both wp and bp increments
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = (idx % 23) + 1; // Spread across possible piece types
    }

    // Set up pieces array: valid indices into board, avoid out-of-bounds
    piece_count = 60; // Less than pieces array size and allows safe traversal
    for (int idx = 0; idx < 62; idx++) {
        if (idx < piece_count) {
            pieces[idx] = (idx * 2) % 144; // Map to valid board indices
        } else {
            pieces[idx] = 0; // Rest are zero, skipped by loop
        }
    }

    // Reset counters
    i = 0;
    j = 0;
    a = 0;
    wp = 0;
    bp = 0;
}