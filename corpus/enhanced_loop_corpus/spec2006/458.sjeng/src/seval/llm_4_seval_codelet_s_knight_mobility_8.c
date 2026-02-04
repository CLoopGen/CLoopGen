#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (d = 0; d < 8; d++) {
    if (board[square + knight_o[d]] != 13)
        continue;
    m++;
}
}
