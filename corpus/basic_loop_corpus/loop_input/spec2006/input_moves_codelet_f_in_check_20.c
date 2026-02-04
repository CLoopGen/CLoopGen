#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize board: set most elements to 13 to allow loop to iterate
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }
    
    // Ensure that eventually we hit a non-13 value to prevent infinite loop
    // Choose a position beyond initial wking_loc + 12 that breaks the loop
    // Let wking_loc be such that l starts at index >= 12
    wking_loc = 0;  // So l starts at 12

    // Set a sentinel value beyond reasonable access
    // Loop does: l = wking_loc + 12, then +=12 each time
    // We need to break when l is within bounds but next would exceed or condition fails
    // Max l: 144 / 12 = 12 steps possible. Let’s break at l = 132 (index 132)
    // So set board[132] to something != 13
    if (wking_loc + 12 < 144) {
        int idx = wking_loc + 12;
        // Traverse multiples of 12 until near end
        while (idx + 12 < 144) {
            idx += 12;
        }
        board[idx] = 0; // Break condition here
    }
}