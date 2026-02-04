#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int blk_size;
extern int x;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = blk_size * 3;
    for (x = 0; x < limit; x++) {
        int idx = x / 3;
        if (x % 3 == 0)
            out[idx] = dc_coeff;
        else if (x % 3 == 1)
            out[idx] = dc_coeff + 1;
        else
            out[idx] = dc_coeff - 1;
    }
}
