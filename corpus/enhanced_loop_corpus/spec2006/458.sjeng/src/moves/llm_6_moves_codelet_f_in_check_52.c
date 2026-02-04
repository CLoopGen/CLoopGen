#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc + 1;
    for (l = temp; board[l] == 13; l += 1) {
        temp = l; // Introduce artificial loop-carried dependence (WAW: l and temp depend on prior iteration)
    }
    l = temp; // Ensure final value of l is preserved
}
