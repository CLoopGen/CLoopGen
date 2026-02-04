#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern double block1[64];
extern double s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    for (j = 0; j < 4; j++) {
        int idx1 = 8 * i + j;
        int idx2 = idx1 + 4;
        double val1 = block[idx1] * s;
        double val2 = block[idx2] * s;
        block1[idx1] = val1 + val2;
        block1[idx2] = val1 - val2;
    }
}
}
