#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int d1, d2;
for (d1 = 0; d1 < 8; d1++) {
    for (d2 = 0; d2 < 1; d2++) {
        if (board[square + knight_o[d1]] == 13)
            m++;
    }
}
}
