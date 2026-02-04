#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int local_l = square - 13;
    for (i = 0; board[local_l] == 13; i++) {
        local_l -= 13;
        m++;
    }
}
