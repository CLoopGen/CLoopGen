#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency
    // We break the independence by making each iteration depend on the previous write
    // via a dummy control condition that forces sequential execution.
    int temp_white = 0, temp_black = 0;
    for (i = 0; i < 11; i++) {
        if (i == 0) {
            white_back_pawn[i] = 7;
            black_back_pawn[i] = 2;
        } else {
            // Force dependence: current write depends on prior index being set
            white_back_pawn[i] = white_back_pawn[i - 1] + (7 - white_back_pawn[i - 1]); // resolves to 7, but creates dependency
            black_back_pawn[i] = black_back_pawn[i - 1] + (2 - black_back_pawn[i - 1]); // resolves to 2, but creates dependency
        }
    }
}
