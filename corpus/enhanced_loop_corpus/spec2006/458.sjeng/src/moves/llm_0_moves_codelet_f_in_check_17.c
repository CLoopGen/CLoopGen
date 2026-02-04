#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth = 0; depth < 2 && l >= 0; ++depth) {
    for (l = wking_loc - 13; board[l] == 13; l -= 13)
        ;
}
}
