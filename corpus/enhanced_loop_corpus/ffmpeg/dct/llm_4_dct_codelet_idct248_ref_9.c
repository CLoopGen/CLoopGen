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
        int index_base = 8 * (2 * i);
        for (j = 0; j < 8; j++) {
            int idx1 = index_base + j;
            int idx2 = index_base + 8 + j;
            double val1 = block[idx1];
            double val2 = block[idx2];
            if ((i + j) % 2 == 0) {
                block1[idx1] = (val1 + val2) * s;
                block1[idx2] = (val1 - val2) * s;
            } else {
                block1[idx1] = (val2 + val1) * s;
                block1[idx2] = (val2 - val1) * s;
            }
        }
    }
}
