#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int k;
extern int curr_diff[8][8];
extern int diff8x8[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i++)
            for (k = j * 8 + i; k < j * 8 + i + 1; k++)
                diff8x8[k] = curr_diff[j][i];
}
