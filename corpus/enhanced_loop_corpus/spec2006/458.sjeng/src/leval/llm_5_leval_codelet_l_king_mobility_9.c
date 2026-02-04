#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int king_o[8];
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (d = 0; d < 8; d++) {
    m += (board[square + king_o[d]] == 13) ? 1 : 0;
}
}
