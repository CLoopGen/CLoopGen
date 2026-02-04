#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    wking_loc = 0;
    // Ensure the loop terminates within bounds: set a sentinel value beyond wking_loc
    board[143] = 0;  // This ensures board[l] != 13 at some point before overflow
    l = 0;
}