#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_w[11], temp_b[11];
    for (i = 0; i < 11; i++) {
        temp_w[i] = 7;
        temp_b[i] = 2;
    }
    for (i = 0; i < 11; i++) {
        white_back_pawn[i] = temp_w[i];
        black_back_pawn[i] = temp_b[i];
    }
}
