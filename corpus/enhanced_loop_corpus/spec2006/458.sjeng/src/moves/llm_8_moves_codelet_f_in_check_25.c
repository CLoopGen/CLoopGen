#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = wking_loc + 12;
    for (l = temp; board[l] == 13 && (l - wking_loc) < 144; l += 12) {
        temp += 2;
    }
}
