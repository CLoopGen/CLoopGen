#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except the last few elements to prevent out-of-bounds
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Set bking_loc such that the loop starts near the beginning but leaves room for incrementing
    // We want to ensure l does not exceed 143 during loop execution
    bking_loc = 100; // This makes l start at 101, and loop until it hits a non-13 value

    // Modify an element beyond bking_loc + 1 to break the loop eventually
    // The loop condition is: board[l] == 13, so set one element to something else
    // Start at l = bking_loc + 1 = 101, and stop when board[l] != 13
    // So we set board[110] to a different value to break the loop after 9 iterations
    board[110] = 0;

    // Initialize l to a safe value (will be overwritten in loop, but good practice)
    l = 0;
}