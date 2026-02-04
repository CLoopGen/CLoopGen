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
    for (i = 0; i < 20 * iter; i++) {
        int abs_val = ccr_buf[i];
        if (abs_val < 0) {
            abs_val = -abs_val;
        }
        if (abs_val > max) {
            max = abs_val;
        }
    }
}
