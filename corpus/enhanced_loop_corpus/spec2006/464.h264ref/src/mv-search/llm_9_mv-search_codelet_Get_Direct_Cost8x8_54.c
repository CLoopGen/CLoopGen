#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int k;
extern int curr_diff[8][8];
extern int diff8x8[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 8; i++) {
            diff8x8[k] = curr_diff[2*j][i];
            k++;
            diff8x8[k] = curr_diff[2*j+1][i];
            k++;
        }
    }
}
