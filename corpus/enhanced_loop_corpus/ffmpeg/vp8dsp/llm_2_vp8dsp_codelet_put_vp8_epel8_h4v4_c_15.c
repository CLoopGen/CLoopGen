#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled filter computation
    // Instead of strided access on tmp, we use a base pointer and offset indexing
    // to promote consecutive memory access patterns which may improve cache locality.

    uint8_t *tmp_base;
    for (y = 0; y < h; y++) {
        tmp_base = tmp + y * 8;  // Base pointer for current row in tmp
        for (x = 0; x < 8; x++) {
            int sum = filter[2] * tmp_base[x]                // tmp[x + 0*8]
                    - filter[1] * tmp_base[x - 1]            // tmp[x - 1*8]
                    + filter[3] * tmp_base[x + 1]            // tmp[x + 1*8]
                    - filter[4] * tmp_base[x + 2];           // tmp[x + 2*8]
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        tmp += 8;
    }
}
