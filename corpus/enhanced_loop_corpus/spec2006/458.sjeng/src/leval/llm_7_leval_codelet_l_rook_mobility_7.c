#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square + 12;
    for (int i = 0; i < 10; i++) {
        l = prev_l + i * 12;
        if (board[l] != 13) break;
        m++;
    }
}
