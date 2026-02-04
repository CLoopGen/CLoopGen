#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square + 11;
    int next_l;
    for (int i = 0; (next_l = prev_l + 11), board[prev_l] == 13; prev_l = next_l, i++) {
        m++;
        if (i > 143) break; // Prevent unbounded behavior
    }
    l = prev_l;
}
