#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int base = square + 13;
    for (i = 0; board[base + i * 13] == 13; i++) {
        m++;
        l = base + i * 13;
    }
}
