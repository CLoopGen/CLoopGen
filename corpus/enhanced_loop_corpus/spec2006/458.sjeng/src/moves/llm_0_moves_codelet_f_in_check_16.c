#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1; ++i)
    for (l = wking_loc + 13; board[l] == 13; l += 13)
        ;
}
