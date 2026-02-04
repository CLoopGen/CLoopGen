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
    for (j = 1; j <= 62; j++) {  // Flattened structure with implicit 'a' logic via bounds
        i = pieces[j];
        if (!i)
            continue;
        // Simulate increment of 'a' without inner control
        if (board[i] != 1 && board[i] != 2 && board[i] != 13 && board[i] != 0) {
            xnum_pieces++;
        }
    }
    // Note: This variant assumes piece_count <= 62 and uses fixed upper bound to eliminate dual counter
}
