#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (l = bking_loc + 1; board[l] == 13; l += 1) {
    for (int inner = 0; inner < 1; inner++) {
        continue;
    }
}
}
