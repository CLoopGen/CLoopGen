#include <stdio.h>
#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a stopping condition
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set bking_loc to a position near the top of the column so we can subtract 12 safely
    // We want to walk upwards in steps of 12 (assuming 12 is row size), so pick a starting row
    // Let's place bking_loc in the 5th row (index 60) so we have room to go up multiple times
    bking_loc = 60;

    // Place a non-13 value at a higher offset to stop the loop after a few iterations
    // The loop stops when board[l] != 13, so set one element above to break
    int temp = bking_loc;
    int steps = 0;
    while (temp >= 12) { // Ensure we don't go out of bounds
        temp -= 12;
        steps++;
        if (steps == 3) { // Stop after 3 steps to bound execution time
            board[temp] = 0; // This will stop the loop when reached
            break;
        }
    }

    // Initialize l to avoid undefined behavior if used before loop
    l = bking_loc;
}