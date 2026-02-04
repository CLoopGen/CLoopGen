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
for (i = 0; i < 2; i++) {
    int base_i = 8 * (4 * i);
    for (j = 0; j < 8; j++) {
        int idx = base_i + j;
        double b0 = block[idx];
        double b1 = block[idx + 8];
        double b2 = block[idx + 16];
        double b3 = block[idx + 24];
        double sum0 = (b0 + b1) * s;
        double dif0 = (b0 - b1) * s;
        double sum1 = (b2 + b3) * s;
        double dif1 = (b2 - b3) * s;
        block1[idx + 0]  = sum0;
        block1[idx + 8]  = dif0;
        block1[idx + 16] = sum1;
        block1[idx + 24] = dif1;
    }
}
}
