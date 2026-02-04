#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = square - 12;
    int acc = 0;
    for (; board[i] == 13; i -= 12) {
        acc += (board[i + 12] != 13) ? 0 : 1; // Introduce indirect dependency on next iteration's condition
        m++; // Maintain original side effect on m
    }
    if (acc > 0) {
        m += acc - 1;
    }
}
