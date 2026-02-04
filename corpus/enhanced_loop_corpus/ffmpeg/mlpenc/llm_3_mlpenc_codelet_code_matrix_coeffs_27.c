#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coeff_mask;
extern unsigned int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const unsigned int strides[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    for (bits = 0; bits < 14; bits++) {
        unsigned int idx = strides[bits];
        if (coeff_mask & (1U << idx)) break;
    }
}
