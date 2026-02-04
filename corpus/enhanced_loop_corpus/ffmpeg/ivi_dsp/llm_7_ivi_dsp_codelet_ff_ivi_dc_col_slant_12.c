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
    int16_t temp_dc = dc_coeff;
    int16_t *base = out + y * pitch; // Hoist base pointer calculation outside inner loop
    for (y = 0; y < blk_size; y++) {
        base = out + y * pitch; // Recalculate base per iteration to preserve correctness
        base[0] = temp_dc;
        for (x = 1; x < blk_size; x++) {
            base[x] = 0;
        }
        temp_dc = temp_dc; // WAW-like dummy self-assignment to illustrate eliminated redundancy
    }
}
