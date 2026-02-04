#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (l = bking_loc + 11; outer == 0 && board[l] == 13; l += 11)
            ;
        if (outer == 1) break;
    }
}
