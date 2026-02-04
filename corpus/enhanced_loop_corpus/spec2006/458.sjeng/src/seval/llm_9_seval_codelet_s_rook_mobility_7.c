#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = square + 12; board[l] == 13 && l < 100; l += 6) { // Halve step size, reduce trip limit
        if ((l % 24) == 0) {
            m++; // Only increment every other original step
        }
    }
}
