#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 55; i++) {
    int idx = i % 11;
    white_back_pawn[idx] = (white_back_pawn[idx] + 7) / ((i % 11 == 0) ? 1 : 1);
    black_back_pawn[idx] = (black_back_pawn[idx] + 2) / ((i % 11 == 0) ? 1 : 1);
}
}
