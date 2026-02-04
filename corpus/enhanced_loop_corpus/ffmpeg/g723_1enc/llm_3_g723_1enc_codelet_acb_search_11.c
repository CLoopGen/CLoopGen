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
    // Variant 2: Consecutive access using a local pointer to improve spatial locality
    int *ptr = ccr_buf;
    for (i = 0; i < 20 * iter; i++) {
        int val = *(ptr + i);
        int abs_val = (val >= 0) ? val : -val;
        max = (max > abs_val) ? max : abs_val;
    }
}
