#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = wking_loc + 13;
    for (l = next_index; board[l] == 13; next_index = l + 13, l = next_index)
        ;
}
