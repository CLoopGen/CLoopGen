#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = bking_loc + 13;
    for (l = next_index; board[l] == 13; next_index = l + 13, l = next_index) {
        // Introduce WAR-like pattern: next_index is read before being updated in next iteration
        // Loop-carried dependency on next_index is added
    }
}
