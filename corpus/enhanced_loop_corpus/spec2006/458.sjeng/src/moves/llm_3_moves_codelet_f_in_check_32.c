#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *p = board + wking_loc - 11;
for (l = wking_loc - 11; p[l - (wking_loc - 11)] == 13; l -= 11, p -= 11)
    ;
}
