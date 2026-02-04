#include <inttypes.h>

int board[144];
int piece_count;
int pieces[62];
int xnum_pieces;
int j;
int a;
int i;

void init_vars() {
    // Initialize board array with safe values within valid index range
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = idx % 14; // Ensures values in range [0,13], so comparisons are safe
    }

    // Initialize pieces array: ensure indices stay within [0,143] for board access
    for (int idx = 0; idx < 62; idx++) {
        pieces[idx] = (idx * 2 + 1) % 144; // Non-zero values mostly, but some zero to trigger 'continue'
    }

    // Set piece_count to maximum logical value (number of non-zero entries we might process)
    piece_count = 61; // Less than 62 to allow j++ to stay in bounds

    // Initialize loop counters and accumulators
    xnum_pieces = 0;
    j = 0; // Will be set to 1 in loop, but initialize safely
    a = 1;
    i = 0;
}