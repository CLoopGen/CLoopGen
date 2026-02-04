#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int king_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (d = 0; d < 8; d++) {
            if (board[square + king_o[d]] == 13)
                m++;
        }
    }
}
