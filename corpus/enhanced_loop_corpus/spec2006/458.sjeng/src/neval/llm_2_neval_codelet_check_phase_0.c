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
    // Variant 1: Strided memory access on 'pieces' array with stride of 2, simulating non-unit stride pattern
    // Also pre-increment j to match original logic flow
    for (j = 1, a = 1; (a <= piece_count); ) {
        i = pieces[j];
        j += 2;  // Strided access: jump by 2
        if (!i)
            continue;
        else
            a++;
        if (j > 62) break;  // Prevent out-of-bounds since we stride
        if (board[i] != 1 && board[i] != 2 && board[i] != 13 && board[i] != 0) {
            xnum_pieces++;
        }
    }
}
