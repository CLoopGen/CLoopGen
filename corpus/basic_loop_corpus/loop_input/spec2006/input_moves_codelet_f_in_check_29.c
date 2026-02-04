#include <stdint.h>
#include <string.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    memset(board, 13, sizeof(board));
    wking_loc = 10; // Ensures l starts at 23, well within bounds
    // Set a sentinel value to break the loop before out-of-bounds
    // Loop advances by 13: sequence is l = 23, 36, 49, 62, 75, 88, 101, 114, 127...
    // board has size 144, so index 127+13=140 is safe, but next would be 153 -> invalid
    // So we break at or before index >= 144 - 13 = 131
    // Let's set board[130] to non-13 to break early enough
    board[130] = 0;
}