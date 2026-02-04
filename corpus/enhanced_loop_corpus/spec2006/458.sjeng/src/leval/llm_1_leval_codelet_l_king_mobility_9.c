#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int king_o[8];
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int temp_d = 0; temp_d < 8; temp_d++) {
        d = temp_d;
        if (board[square + king_o[d]] == 13)
            m++;
    }
}
