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
    max = 0;
    for (i = 0; i < 20 * iter; ++i) {
        int val = ccr_buf[i];
        int neg_val = -val;
        int use_val = val >= 0 ? val : neg_val;
        if (use_val > max) {
            max = use_val;
        } else {
            continue;
        }
    }
}
