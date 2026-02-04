#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int king_o[8];
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int d1, d2;
    for (d1 = 0, d2 = 7; d1 < 4; d1++, d2--) {
        if (board[square + king_o[d1]] == 13)
            m++;
        if (board[square + king_o[d2]] == 13)
            m++;
    }
}
