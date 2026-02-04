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
for (i = 0; i < 40 * iter; i += 2) {
    int abs_val = ccr_buf[i] >= 0 ? ccr_buf[i] : -ccr_buf[i];
    if (abs_val > max) {
        max = abs_val;
    }
}
}
