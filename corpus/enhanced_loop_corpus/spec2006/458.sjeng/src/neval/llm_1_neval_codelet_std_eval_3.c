#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 11; i += 2) {
    white_back_pawn[i] = 7;
    black_back_pawn[i] = 2;
    if (i + 1 < 11) {
        white_back_pawn[i+1] = 7;
        black_back_pawn[i+1] = 2;
    }
}
}
