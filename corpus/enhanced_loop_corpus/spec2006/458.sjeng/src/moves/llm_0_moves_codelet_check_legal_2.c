#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_l;
for (temp_l = bking_loc - 1; board[temp_l] == 13; temp_l -= 1) {
    l = temp_l;
    for (int inner = 0; inner < 1; inner++) { 
        break; 
    }
}
l = temp_l;
}
