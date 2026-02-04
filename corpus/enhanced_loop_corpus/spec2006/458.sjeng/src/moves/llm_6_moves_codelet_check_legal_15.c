#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_l = wking_loc + 11;
    for (l = temp_l; board[l] == 13; ){
        l += 11;
        temp_l = l; // Introduce artificial WAW dependency: l and temp_l update in sequence
    }
    l = temp_l; // Final write to preserve loop-carried value
}
