#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (l = bking_loc + 1; l < 144 && board[l] == 13; l += 1) {
    int inner_counter = 0;
    for (; inner_counter < 1 && board[l] == 13; inner_counter++) {
        continue;
    }
    if (board[l] != 13) break;
}
}
