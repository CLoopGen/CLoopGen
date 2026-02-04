#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 22; i += 2) {
    for (j = 0; j < 1; j++) {
        white_back_pawn[i/2] = 5 + 2;
        black_back_pawn[i/2] = 3 - 1;
    }
}
}
