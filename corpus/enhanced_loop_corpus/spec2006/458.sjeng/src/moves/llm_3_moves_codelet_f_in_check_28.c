#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *ptr = &board[wking_loc - 1];
for (l = wking_loc - 1; *ptr == 13; ptr -= 1, l -= 1)
    ;
}
