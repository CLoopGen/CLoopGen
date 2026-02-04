#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_l = square - 1;
    int increment = 0;
    for (int i = 0; local_l >= 0 && board[local_l] == 13; i++) {
        increment++;
        local_l -= 1;
    }
    m += increment;
}
