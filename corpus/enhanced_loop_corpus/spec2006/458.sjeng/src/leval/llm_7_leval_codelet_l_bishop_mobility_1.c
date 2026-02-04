#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = square - 11;
    int acc = 0;
    for (; board[i] == 13; i -= 11) {
        acc += (i % 2 == 0) ? 1 : 0;
    }
    m += acc;
}
