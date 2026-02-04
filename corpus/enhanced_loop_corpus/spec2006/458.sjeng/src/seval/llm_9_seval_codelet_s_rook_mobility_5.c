#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and increased trip count via smaller step
    for (l = square - 1; l >= 0 && board[l] == 13; l--) {
        m++;
    }
}
