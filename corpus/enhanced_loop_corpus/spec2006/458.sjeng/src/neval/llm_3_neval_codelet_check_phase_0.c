#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int xnum_pieces;
extern int j;
extern int a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via arithmetic)
    // Use a virtual "indirection" through modulo and offset to simulate irregular access pattern
    int idx_map[62];
    for (int k = 0; k < 62; k++) {
        idx_map[k] = (k * 7) % 61;  // Generate pseudo-random order within bounds
    }
    for (j = 0, a = 1; (a <= piece_count && j < 62); j++) {
        i = pieces[idx_map[j]];  // Indirect access via mapped index
        if (!i)
            continue;
        else
            a++;
        if (board[i] != 1 && board[i] != 2 && board[i] != 13 && board[i] != 0) {
            xnum_pieces++;
        }
    }
}
