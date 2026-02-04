#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int16_t *ac_val;
extern int k;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 4; k++) {
        int shift1 = k << sh;
        int shift2 = (k + 1) << sh;
        block[shift1] += ac_val[k];
        block[shift2] += ac_val[k + 1] * 2;
        block[shift1] -= (ac_val[k] >> 1);
    }
}
