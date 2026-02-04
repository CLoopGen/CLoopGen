#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = square + 11; l < 144 && board[l] == 13; l += 11) {
        if ((l % 2) == 0) {
            m++; // Only update m on even-indexed iterations, reducing effective trip count and adding conditional computation
        }
    }
}
