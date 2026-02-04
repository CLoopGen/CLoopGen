#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    int trip_count = blk_size * blk_size;
    int16_t *ptr = out;
    for (int i = 0; i < trip_count; i++) {
        ptr[i] = dc_coeff;
        if ((i + 1) % blk_size == 0) 
            ptr += pitch - blk_size;
    }
}
