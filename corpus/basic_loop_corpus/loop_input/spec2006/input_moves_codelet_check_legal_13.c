#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 for indices that will be accessed
    // Set a region of board to 13, but ensure we do not go out of bounds
    // The loop starts at wking_loc + 13 and increments by 13 each time
    // We need to choose wking_loc so that l stays within [0, 143]

    // Choose wking_loc such that we can have several iterations without overflow
    // Let's set wking_loc = 1 so that initial l = 14
    // Then l goes: 14, 27, 40, 53, 66, 79, 92, 105, 118, 131 -> next would be 144 which is out of bounds
    // So we allow 10 iterations by setting board[l] == 13 for these indices

    wking_loc = 1;

    // Initialize all board elements to 13 only for indices accessed in the loop
    for (int i = wking_loc + 13; i < 144; i += 13) {
        board[i] = 13;
    }

    // Ensure that eventually the condition fails -- set one beyond the valid sequence to break
    // But our loop stops at 131 (since 131+13=144 >= 144), so no write past array

    // Explicitly make sure no out-of-bounds access by ensuring last increment exits
    // Already guaranteed by loop condition and array size

    // Initialize l to some value (will be overwritten in loop)
    l = 0;
}