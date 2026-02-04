#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 16; k++) {
        int idx1 = 64 + 2 * k;
        int idx2 = 64 - k;
        int val1 = -z[idx2];
        int val2 = z[k + 1];
        z[idx1] = val1;
        z[idx1 + 1] = val2;
        
        // Additional computational work to increase intensity
        z[idx1] += (val1 & 0xF) ^ (val2 << 1);
        z[idx1 + 1] -= (val2 & 0x7) + (val1 >> 2);
    }
}
