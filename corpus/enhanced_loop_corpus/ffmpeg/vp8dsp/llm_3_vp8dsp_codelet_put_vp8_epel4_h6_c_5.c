#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access pattern using index scaling to simulate non-unit strides internally
    for (y = 0; y < h; y++) {
        ptrdiff_t src_offset = y * srcstride;
        ptrdiff_t dst_offset = y * dststride;
        for (x = 0; x < 4; x++) {
            ptrdiff_t idx = src_offset + x;
            int sum = filter[2] * src[idx + 0] 
                    - filter[1] * src[idx - 1] 
                    + filter[0] * src[idx - 2] 
                    + filter[3] * src[idx + 1] 
                    - filter[4] * src[idx + 2] 
                    + filter[5] * src[idx + 3] 
                    + 64;
            dst[dst_offset + x] = cm[sum >> 7];
        }
    }
}
