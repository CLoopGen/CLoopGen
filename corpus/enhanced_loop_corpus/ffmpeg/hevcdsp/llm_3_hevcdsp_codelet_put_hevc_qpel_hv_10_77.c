#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x += 2) {
        // Unroll and use strided memory access pattern (process two elements at once)
        int base_idx = x;
        tmp[base_idx]     = (filter[0] * src[base_idx - 3] + filter[1] * src[base_idx - 2] +
                            filter[2] * src[base_idx - 1] + filter[3] * src[base_idx] +
                            filter[4] * src[base_idx + 1] + filter[5] * src[base_idx + 2] +
                            filter[6] * src[base_idx + 3] + filter[7] * src[base_idx + 4]) >> 2;

        if (x + 1 < width) {
            tmp[base_idx + 1] = (filter[0] * src[base_idx + 1 - 3] + filter[1] * src[base_idx + 1 - 2] +
                                 filter[2] * src[base_idx + 1 - 1] + filter[3] * src[base_idx + 1] +
                                 filter[4] * src[base_idx + 1 + 1] + filter[5] * src[base_idx + 1 + 2] +
                                 filter[6] * src[base_idx + 1 + 3] + filter[7] * src[base_idx + 1 + 4]) >> 2;
        }
    }
    src += srcstride;
    tmp += 64;
}
}
