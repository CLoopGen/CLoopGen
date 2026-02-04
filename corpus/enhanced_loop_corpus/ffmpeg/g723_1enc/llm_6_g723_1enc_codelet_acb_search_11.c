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
    int temp_max = max;
    for (i = 0; i < 20 * iter; i++) {
        int abs_val = ccr_buf[i] >= 0 ? ccr_buf[i] : -ccr_buf[i];
        temp_max = temp_max > abs_val ? temp_max : abs_val;
    }
    max = temp_max;
}
