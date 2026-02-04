#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square - 12;
    int next_l;
    for (int i = 0; (next_l = prev_l - 12 * i, board[prev_l - 12 * i] == 13); i++) {
        m++;
        prev_l = next_l;
    }
}
