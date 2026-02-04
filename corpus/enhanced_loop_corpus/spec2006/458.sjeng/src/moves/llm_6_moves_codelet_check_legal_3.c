#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc + 1;
    for (l = temp; board[l] == 13; l += 1) {
        temp = l; // Introduce artificial RAW dependency: use of 'l' before update
    }
    // WAR hazard introduced: 'temp' written here, but read in condition above in subsequent iterations
}
