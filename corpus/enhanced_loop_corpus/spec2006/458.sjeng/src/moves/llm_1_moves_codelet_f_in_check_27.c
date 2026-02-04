#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (l = wking_loc + 1; board[l] == 13 && outer == 0; l += 1)
        ;
    if (outer == 1) {
        for (l = wking_loc + 1; board[l] == 13; l += 1)
            break;
    }
}
}
