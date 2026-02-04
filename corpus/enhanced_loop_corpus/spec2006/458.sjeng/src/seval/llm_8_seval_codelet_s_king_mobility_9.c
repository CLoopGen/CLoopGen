#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int king_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; d < 4; d++) {
        int offset1 = square + king_o[d];
        int offset2 = square + king_o[d + 4];
        if (board[offset1] == 13)
            m++;
        if (board[offset2] == 13)
            m++;
    }
}
