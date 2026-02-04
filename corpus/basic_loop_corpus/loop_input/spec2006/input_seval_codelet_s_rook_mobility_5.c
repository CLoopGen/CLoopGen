#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize the board array with value 13 except near the boundary
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set square to a value such that l starts at index 142 (second to last)
    // Then board[l] will be 13, and we decrement until we hit a non-13 value
    square = 143;
    
    // Modify one element to stop the loop before going out of bounds
    board[71] = 12;  // This ensures when l reaches 71, board[l] != 13, loop stops

    // Initialize l and m to safe values (will be overwritten in loop)
    l = 0;
    m = 0;
}