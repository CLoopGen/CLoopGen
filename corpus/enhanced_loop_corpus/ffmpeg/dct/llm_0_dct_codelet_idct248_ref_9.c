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
    for (j = 0; j < 8; j++) {
        int index = 8 * i + j;
        if (i % 2 == 0) {
            int src1 = 8 * i + j;
            int src2 = 8 * (i + 1) + j;
            block1[src1] = (block[src1] + block[src2]) * s;
            block1[src2] = (block[src1] - block[src2]) * s;
        }
    }
}
}
