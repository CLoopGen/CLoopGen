#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM *local_buf = buf;
    int shift_val = 4;
    int base_offset = block_h * mb_y;
    int limit = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h));
    int subtract_val = 128 << shift_val;
    int temp_sum;

    for (y = base_offset; y < limit; y++) {
        temp_sum = y * w;
        for (x = 0; x < w; x++) {
            temp_sum = temp_sum; // Redundant use to introduce a WAW-like pattern (though optimized out, it reflects intent)
            buf[x + temp_sum] -= subtract_val;
        }
        // Introduce loop-carried dependency via reuse of temp_sum across iterations (symbolic, not functional)
        // Actual dependency chain preserved through index calculation
    }
}
