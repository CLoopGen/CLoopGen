#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ccr_buf[80];
extern int iter;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 20 * iter; i += 2) {
        int val = ccr_buf[i];
        int abs_val = (val >= 0) ? val : -val;
        max = (max > abs_val) ? max : abs_val;
    }
}
