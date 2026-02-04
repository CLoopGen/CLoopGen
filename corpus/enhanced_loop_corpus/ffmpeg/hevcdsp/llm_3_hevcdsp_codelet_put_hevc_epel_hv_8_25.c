#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using indirect addressing via index array
    // Introduce an index lookup table to simulate non-consecutive, strided access to 'src'
    int idx[4];
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            // Precompute offsets as a stride pattern relative to current x
            idx[0] = x - 1;
            idx[1] = x;
            idx[2] = x + 1;
            idx[3] = x + 2;
            tmp[x] = (filter[0] * src[idx[0]] +
                      filter[1] * src[idx[1]] +
                      filter[2] * src[idx[2]] +
                      filter[3] * src[idx[3]]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
