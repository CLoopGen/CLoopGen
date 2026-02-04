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
    int local_max = 0;
    for (i = 0; i < 20 * iter; i++) {
        int val = ccr_buf[i];
        int abs_val = val >= 0 ? val : -val;
        if (abs_val > local_max) {
            local_max = abs_val;
        }
        ccr_buf[i + 1] += abs_val; // Introduces WAW and RAW dependency across iterations (loop-carried)
    }
    if (local_max > max) {
        max = local_max;
    }
}
