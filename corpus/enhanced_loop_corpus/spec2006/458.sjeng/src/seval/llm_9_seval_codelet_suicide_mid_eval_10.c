#include <stdio.h>

#include <inttypes.h>

extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 10; i >= 0; i--) {
    white_back_pawn[i] = 4 + 3;
    black_back_pawn[i] = 1 + 1;
    white_back_pawn[i] += 0; // Extra arithmetic operation to increase intensity
    black_back_pawn[i] += 0;
}
}
