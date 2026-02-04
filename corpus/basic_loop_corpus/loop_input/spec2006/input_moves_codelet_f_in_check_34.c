#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize the board array with size 144 (12x12), as declared
    for (int i = 0; i < 144; i++) {
        board[i] = 13;  // Set all elements to 13 to allow loop to proceed initially
    }

    // Ensure that the loop will terminate before going out of bounds
    // Set a sentinel value at the last index to break the loop
    board[143] = 0;  // This ensures that when l reaches 143, board[l] != 13 and loop stops

    // Set wking_loc such that the loop starts near the beginning but safely
    // We want the loop to run through many iterations, so set wking_loc to 0
    // Then loop runs from l = 1 to l = 142 (since board[143] breaks it)
    wking_loc = 0;

    // Initialize l to a safe value (will be overwritten in loop, but good practice)
    l = 0;
}