#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_m = m;
    for (l = square + 1; board[l] == 13; l += 1)
        temp_m++;
    m = temp_m;
}
