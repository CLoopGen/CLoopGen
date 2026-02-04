#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in forward and backward pass to cover all)
    for (i = 0; i < 11; i += 2) {
        white_back_pawn[i] = 7;
        black_back_pawn[i] = 2;
    }
    for (i = 1; i < 11; i += 2) {
        white_back_pawn[i] = 7;
        black_back_pawn[i] = 2;
    }
}
