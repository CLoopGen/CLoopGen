#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    int offset, next_offset;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            offset = j;
            next_offset = (j + 1 < width) ? j + 1 : j;
            int weighted_sum = 3 * src_local[offset] +
                               4 * src_local[next_offset] +
                               2 * src_local[offset + stride] +
                               3 * src_local[next_offset + stride];
            int computed = ((weighted_sum + 6) * 2731) >> 15;
            dst_local[offset] = (dst_local[offset] + computed + 1) >> 1;
        }
        src_local += stride;
        dst_local += stride;
    }
}
