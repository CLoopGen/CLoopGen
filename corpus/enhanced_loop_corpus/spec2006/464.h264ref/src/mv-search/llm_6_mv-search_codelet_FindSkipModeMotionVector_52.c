#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1, temp2;
    for (by = 0; by < 4; by++)
        for (bx = 0; bx < 4; bx++) {
            temp1 = 0;
            temp2 = 0;
            all_mv[bx][by][0][0][0][0] = temp1;
            all_mv[bx][by][0][0][0][1] = temp2;
        }
}
