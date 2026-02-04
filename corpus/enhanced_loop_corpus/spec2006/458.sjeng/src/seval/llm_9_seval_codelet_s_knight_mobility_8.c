#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; d < 8; d += 2) {
        int offset1 = knight_o[d];
        int offset2 = knight_o[d + 1];
        int val1 = board[square + offset1];
        int val2 = board[square + offset2];
        if (val1 == 13) m++;
        if (d + 1 < 8 && val2 == 13) m++;
    }
}
