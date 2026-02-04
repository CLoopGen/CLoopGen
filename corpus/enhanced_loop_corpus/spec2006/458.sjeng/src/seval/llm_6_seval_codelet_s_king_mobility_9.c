#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int king_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_m = m;
    for (d = 0; d < 8; d++) {
        int offset = king_o[d];
        if (board[square + offset] == 13) {
            temp_m++;
        }
    }
    m = temp_m;
}
