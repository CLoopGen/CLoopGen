#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer_l = 0; outer_l < 1; outer_l++) {
        for (l = square - 13; board[l] == 13; l -= 13) {
            m++;
        }
    }
}
