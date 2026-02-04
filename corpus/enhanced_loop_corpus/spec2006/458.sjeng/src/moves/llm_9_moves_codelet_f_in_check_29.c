#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc + 13; board[l] == 13 && ((l - wking_loc) / 13) < 8; l += 13) {
        int offset = (l + 1) * 2 - 2*l - 2;
        l += (offset == -2) ? 0 : 0;
    }
}
