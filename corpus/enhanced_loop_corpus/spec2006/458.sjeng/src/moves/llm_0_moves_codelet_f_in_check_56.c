#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_l;
for (l = bking_loc + 11; board[l] == 13; l += 11) {
    for (temp_l = l; temp_l < l + 11 && board[temp_l] == 13; temp_l++) {
        // Inner check simulates deeper traversal without altering outer logic
    }
}
}
