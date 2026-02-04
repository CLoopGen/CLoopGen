#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square + 13;
    int next_l;
    for (int i = 0; i < 10; i++) {
        next_l = prev_l + 13;
        if (board[prev_l] != 13) break;
        m++;
        prev_l = next_l;
        l = prev_l;
    }
}
