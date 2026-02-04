#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize board with size 144 as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop to progress
    }

    // Ensure loop terminates within bounds: l starts at wking_loc + 12 and increases by 12
    // We need wking_loc such that initial l is within [0, 143], and loop can run several iterations
    // Choose wking_loc = 0 so l starts at 12
    wking_loc = 0;

    // Modify one element beyond a few iterations to break the loop
    // Let loop run for 10 iterations: l = 12, 24, ..., 120, then set board[132] != 13
    // But 132 >= 144? -> 12 * 11 = 132 -> index 132 is out of bounds (max index 143)
    // So we can safely set breakpoint at index 132 if within bounds? 132 < 144 -> yes.
    // So after 11 steps: l = 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132 -> 11th iteration sets l=132, checks board[132]==13?
    // Then next +=12 makes l=144 -> which is out of bounds. But condition checked before increment.

    // To prevent out-of-bounds access, we must ensure that when board[l] is accessed, l < 144
    // Maximum l value accessed: we want last valid index is 132 (12*11), then next would be 144 -> invalid
    // So we break the chain at l=132: set board[132] to something other than 13

    // But note: loop condition is `board[l] == 13`, so if board[132] != 13, loop stops when l becomes 132
    // However, l is incremented only after the check — no, look:
    //   for (l = wking_loc + 12; board[l] == 13; l += 12)
    // So sequence:
    //   - l = 12 -> check board[12] == 13 -> true -> body (empty) -> l += 12 -> l=24
    //   ...
    //   - l = 132 -> check board[132] == 13 -> if false, exit loop
    // So accessing board[132] is valid only if 132 < 144 -> yes, 132 < 144
    // But 132+12=144 -> not accessed because condition fails or loop exits

    // So set board[132] = 0 to break the loop at l=132
    if (132 < 144) {
        board[132] = 0;
    }
}