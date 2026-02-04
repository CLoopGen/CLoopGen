#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_m = 0;
    for (d = 0; d < 4; d++) {
        if (board[square + knight_o[d]] == 13)
            temp_m++;
        if (board[square + knight_o[7 - d]] == 13)
            temp_m++;
    }
    m += temp_m;
}
