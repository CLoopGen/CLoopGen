#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_white[11];
    int temp_black[11];
    for (i = 0; i < 11; i++) {
        temp_white[i] = 7;
        temp_black[i] = 2;
    }
    for (i = 0; i < 11; i++) {
        white_back_pawn[i] = temp_white[i];
        black_back_pawn[i] = temp_black[i];
    }
}
