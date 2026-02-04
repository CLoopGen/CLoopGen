#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    wking_loc = 0;
    for (int i = 0; i < 144; ++i) {
        board[i] = (i > wking_loc && (i - wking_loc) % 13 == 0) ? 13 : 0;
    }
    // Ensure the loop terminates by setting a non-13 value at some point
    // We set the last valid index in bounds to break the loop
    int idx = wking_loc + 13;
    while (idx < 144) {
        if (idx + 13 >= 144) {
            board[idx] = 0; // Break condition
            break;
        }
        idx += 13;
    }
}