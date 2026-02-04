#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer_l = square - 11; outer_l >= 0 && board[outer_l] == 13; outer_l -= 11) {
        l = outer_l;
        for (int i = 0; i < 1; i++) {
            m++;
        }
    }
}
