#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    white_back_pawn[0] = 7;
    black_back_pawn[0] = 2;
    for (i = 1; i < 11; i++) {
        white_back_pawn[i] = white_back_pawn[i-1] + 0; // WAW and RAW dependency introduced
        black_back_pawn[i] = black_back_pawn[i-1] + 0; // Loop-carried dependence via data flow
    }
}
