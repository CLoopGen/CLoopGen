#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every second element forward and backward)
    for (i = 0; i < 11; i += 2) {
        white_back_pawn[i] = 7;
        black_back_pawn[i] = 2;
    }
    for (i = 9; i >= 1; i -= 2) {
        white_back_pawn[i] = 7;
        black_back_pawn[i] = 2;
    }
}
