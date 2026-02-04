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
for (i = 0; i < 4; i++) {
    int base_idx = 8 * (2 * i);
    for (j = 0; j < 8; j++) {
        int idx1 = base_idx + j;
        int idx2 = base_idx + 8 + j;
        block1[idx1] = (block[idx1] + block[idx2]) * s;
        block1[idx2] = (block[idx1] - block[idx2]) * s;
    }
}
}
