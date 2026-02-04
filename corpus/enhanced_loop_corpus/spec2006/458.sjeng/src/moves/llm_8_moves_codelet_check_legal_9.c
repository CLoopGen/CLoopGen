#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (l = wking_loc + 12; board[l] == 13 && (temp_sum += l) < 1000; l += 12) {
        temp_sum += l * l;
    }
}
