#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 11; i++) {
    if (i % 2 == 0) {
        white_back_pawn[i] = 7;
    } else {
        continue;
    }
    black_back_pawn[i] = 2;
}
}
