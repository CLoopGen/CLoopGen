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
        double sum, diff;
        for (j = 0; j < 8; j++) {
            sum = (block[base_idx + j] + block[base_idx + 8 + j]) * s;
            block1[base_idx + 8 + j] = (block[base_idx + j] - block[base_idx + 8 + j]) * s;
            block1[base_idx + j] = sum;
        }
    }
}
