#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize board with size 144 as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop to proceed initially
    }

    // Choose wking_loc such that l starts within bounds and can decrement by 11 multiple times
    // We want to avoid out-of-bounds access: l = wking_loc - 11 must be >= 0 and decreasing by 11 until condition fails
    // Set wking_loc to a value near the upper end of valid range to allow many iterations
    wking_loc = 143;  // Max index in board
    // Then initial l = wking_loc - 11 = 132
    // We'll break when board[l] != 13, so set one element to break the chain after desired number of iterations

    // To control execution time (~0.01 seconds), estimate iterations:
    // Assume ~1ns per iteration -> need ~10M iterations for 0.01s
    // But array only allows 144/11 ~ 13 steps maximum from any start point.
    // Therefore, cannot achieve timing via long chain; instead simulate cost elsewhere?

    // However, loop is memory-bound and very short (max ~13 iterations). 
    // Actual runtime will be << 0.01s, but we cannot extend data size due to fixed board[144].
    // So initialize conservatively to avoid UB.

    // Terminate the loop when l reaches 11 (so we go: 132, 121, ..., 22, 11, then next would be 0)
    // Set board[0] to non-13 to break at l=0 if reached
    board[0] = 0;

    // Also ensure no underflow beyond 0
    // The loop stops when board[l] != 13, so set an early exit?
    // But to maximize iterations within bounds:
    // Start at l = 132, then 121, 110, 99, 88, 77, 66, 55, 44, 33, 22, 11, 0 -> 13 iterations
    // At l=0: board[0]==0 !=13 -> exits

    // So set all positions along diagonal: indices divisible by 11 starting from 132 down to 11
    // They are already 13 by initialization above.

    // Just leave as-is: wking_loc=143, board[0]=0, rest 13
}