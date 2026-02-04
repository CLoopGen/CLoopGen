#include <stdio.h>
#include <inttypes.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
char active[400];
int k;

void init_vars() {
    // Initialize board array with size 421, ensuring no out-of-bounds access
    // Board indices used: k, k+20, k-1, k-20, k+1 -> max index is k+20
    // Loop runs from k=21 to 360 (since (19+1)*(19+1) = 400), so max accessed index is 360+20 = 380
    // Ensure we only access within [0,420] -> safe since 380 < 421

    memset(board, 0, sizeof(board));
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 381) ? 3 : 0;  // Set core region to 3, others to 0
    }

    // Initialize active array (size 400)
    // Accesses: k, k+20, k-1, k-20, k+1; k from 21 to 399
    // Max index: 399+1 = 400 -> need to ensure bounds
    // But active is only size 400 -> indices 0..399
    // So k+1 at k=399 would be 400 -> out of bounds!
    // Therefore, adjust loop bound: original condition is k < 400, but we must avoid k=399
    // However, the logic uses k < (19+1)*(19+1) = 400, so k goes up to 399
    // Need to prevent accessing active[400] -> so guard conditionally in loop or initialize larger?
    // But spec says: define as declared -> active[400], so we must work within bounds

    // To prevent out-of-bounds, ensure that when k=399, we don't access active[k+1]
    // But the loop condition allows k=399, and then accesses active[400] -> undefined
    // Therefore, adjust data initialization to make such cases skip via conditionals
    // We'll set board[k] != 3 for k near boundaries to skip problematic iterations

    memset(active, 0, sizeof(active));
    
    // Random-like initialization within safe bounds
    for (int i = 1; i < 380; i++) {
        if (i % 7 == 0) active[i] = 1;
        else if (i % 11 == 0) active[i] = 2;
        else if (i % 13 == 0) active[i] = 3;
        else active[i] = 0;
    }

    // Fix boundary regions to avoid out-of-bounds access effects
    // For k near 399: set board[k] != 3 so it skips
    for (int k = 380; k < 400; k++) {
        if (k < 421) board[k] = 0;  // Skip processing for k>=380
    }

    // Ensure first few elements of board are not 3 to avoid early boundary issues
    for (int k = 0; k < 21; k++) {
        board[k] = 0;
    }
}