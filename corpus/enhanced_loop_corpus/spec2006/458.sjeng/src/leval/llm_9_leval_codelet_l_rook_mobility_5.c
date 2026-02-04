#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (l = square - 1; board[l] == 13 && l >= 12; l -= 12) {
        temp_sum += board[l + 1] * board[l - 1];
        m++;
    }
    m += temp_sum & 0xF;
}
