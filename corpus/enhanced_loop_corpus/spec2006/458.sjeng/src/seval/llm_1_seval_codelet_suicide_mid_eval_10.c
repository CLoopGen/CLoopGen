#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 11; i += 2) {
        for (int j = 0; j < 2 && (i + j) < 11; j++) {
            white_back_pawn[i + j] = 7;
            black_back_pawn[i + j] = 2;
        }
    }
}
