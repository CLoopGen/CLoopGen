#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (l = wking_loc + 12; board[l] == 13; l += 12)
    ;

}
