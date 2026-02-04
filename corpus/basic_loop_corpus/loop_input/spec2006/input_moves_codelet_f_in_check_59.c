#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board with size 144 as declared
    for (int i = 0; i < 144; i++) {
        board[i] = 13;  // Set all elements to 13 to allow loop to progress
    }
    // Ensure loop terminates: set a sentinel value beyond bking_loc
    // Choose bking_loc such that there is space after it, but avoid overflow
    bking_loc = 100;  // Leaves 43 elements after (index 101 to 143)
    // Set element at valid index beyond sequence to break condition
    // Loop starts at bking_loc + 1 = 101, so make board[101...] eventually not 13
    // We'll set board[143] = 0 to terminate the loop eventually
    // But we want loop to run long enough to take ~0.01s — however, 144 elements is fixed
    // So we cannot have large data here due to fixed array size

    // Given fixed small array, actual runtime will be negligible (< 1us).
    // But requirement asks for 1MB–256MB unless length is specified.
    // However, board is fixed at 144 ints — we cannot change its size.

    // Therefore, we must respect the declared size.
    // The loop will run from 101+1=102 until it finds non-13.
    // Set last element to break condition
    if (bking_loc + 1 < 144) {
        // We need at least one non-13 after bking_loc to prevent out-of-bounds
        board[143] = 0;  // Set last element to 0 so loop stops before going out of bounds
    }
}
// Note: Due to fixed small array size (144 ints), the loop executes in nanoseconds.
// Performance target of 0.01s cannot be met without changing data size,
// but changing board size would violate the given declaration.
// Initialization ensures memory safety and correct termination within bounds.