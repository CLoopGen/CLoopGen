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
    int outer_i;
    for (outer_i = 0; outer_i < 20 * iter; outer_i += 4) {
        int temp_max = max;
        for (i = outer_i; i < outer_i + 4 && i < 20 * iter; i++) {
            int abs_val = (ccr_buf[i] >= 0) ? ccr_buf[i] : -ccr_buf[i];
            if (abs_val > temp_max)
                temp_max = abs_val;
        }
        if (temp_max > max)
            max = temp_max;
    }
}
