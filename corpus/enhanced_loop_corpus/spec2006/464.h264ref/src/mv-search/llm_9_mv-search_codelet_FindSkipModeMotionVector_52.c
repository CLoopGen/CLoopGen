#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (by = 0; by < 2; by += 1)
    for (bx = 0; bx < 2; bx += 1)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                all_mv[bx*2+i][by*2+j][0][0][0][0] = 0;
                all_mv[bx*2+i][by*2+j][0][0][0][1] = 0;
            }

}
