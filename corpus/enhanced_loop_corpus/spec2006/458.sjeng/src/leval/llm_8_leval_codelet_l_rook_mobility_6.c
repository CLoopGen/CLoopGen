#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = square + 2; board[l] == 13 && board[l+1] == 13; l += 2)
        m += 2;
}
