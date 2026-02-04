#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
for (i = 0; i < 11; i++) {
    int idx = indices[i];
    white_back_pawn[idx] = 7;
    black_back_pawn[idx] = 2;
}
}
