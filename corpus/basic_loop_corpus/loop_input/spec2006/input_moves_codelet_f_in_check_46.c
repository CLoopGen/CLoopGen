#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a boundary condition
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set a sentinel value to break the loop after a predictable number of iterations
    // The loop decrements by 12 starting from bking_loc - 12, so we need to ensure it doesn't underflow
    // Choose bking_loc such that the loop runs through several elements but stops before index 0

    // Place the stopping condition at index 0 (board[0] != 13 will stop the loop when l reaches 0)
    board[0] = 0;

    // Set bking_loc to a position where l starts at 12*k - 12 and walks down to 0
    // For example, if bking_loc = 12, then l starts at 0 -> doesn't enter loop
    // We want several iterations: let's start at 60 (so l starts at 48, then 36, 24, 12, 0 -> stop)
    // But note: loop condition is checked *after* assignment: l = bking_loc - 12, then check board[l] == 13
    // So if bking_loc = 12, l = 0, check board[0]==13? No -> exit. Only one memory access.

    // To get more iterations, place the non-13 value early and start later.
    // Let’s set bking_loc = 72 -> l starts at 60, then 48, 36, 24, 12, 0 -> at 0, board[0]=0 !=13 -> break
    // That gives 5 iterations: indices 60,48,36,24,12 — all must be 13.

    bking_loc = 72;

    // Ensure all these indices are within [0,143] and have value 13
    // Indices accessed: 60, 48, 36, 24, 12, then 0 (where it breaks)
    // All are valid in 144-element array (0..143)

    // Already initialized above.

    // Additional safety: don't go below 0
    // Our sequence: l = 60,48,36,24,12,0 -> next would be -12, but loop breaks at 0 because board[0]!=13
}