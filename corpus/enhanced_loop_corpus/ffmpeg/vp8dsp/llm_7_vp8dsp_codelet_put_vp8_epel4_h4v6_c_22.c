#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_tmp = tmp;
    const uint8_t *local_src = src;
    for (y = 0; y < h + 6 - 1; y++) {
        uint8_t temp_vec[4]; // Local buffer to eliminate immediate write-after-write (WAW) on tmp
        for (x = 0; x < 4; x++) {
            int offset = x * 1;
            // Reorder memory accesses and remove direct left-to-right RAW dependency by precomputing index
            int index = (filter[2] * local_src[offset] -
                         filter[1] * local_src[offset - 1] +
                         filter[3] * local_src[offset + 1] -
                         filter[4] * local_src[offset + 2] + 64) >> 7;
            temp_vec[x] = cm[index]; // Store into temporary array first
        }
        // Eliminate loop-carried dependency on tmp by writing only after full computation
        for (x = 0; x < 4; x++) {
            local_tmp[x] = temp_vec[x];
        }
        local_tmp += 4;
        local_src += srcstride;
    }
}
