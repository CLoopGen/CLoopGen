#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int king_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int d1 = 0; d1 < 2; d1++) {
        for (int d2 = 0; d2 < 4; d2++) {
            d = d1 * 4 + d2;
            if (board[square + king_o[d]] == 13)
                m++;
        }
    }
}
