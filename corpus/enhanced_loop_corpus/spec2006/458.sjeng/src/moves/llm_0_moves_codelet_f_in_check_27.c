#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth = 0; depth < 1; depth++) {
    for (l = wking_loc + 1; board[l] == 13; l += 1)
        ;
}
}
