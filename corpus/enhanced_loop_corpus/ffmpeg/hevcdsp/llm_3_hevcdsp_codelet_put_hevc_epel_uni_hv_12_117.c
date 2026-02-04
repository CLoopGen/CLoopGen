#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element to change access pattern
    uint16_t *src_ptr = src;
    int16_t *tmp_ptr = tmp;
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x += 2) {  // Stride of 2 in x-direction
            // Handle two elements at once with adjusted indexing
            int val1 = (filter[0] * src_ptr[x - 1] +
                        filter[1] * src_ptr[x] +
                        filter[2] * src_ptr[x + 1] +
                        filter[3] * src_ptr[x + 2]) >> 4;

            int val2 = (filter[0] * src_ptr[x] +
                        filter[1] * src_ptr[x + 1] +
                        filter[2] * src_ptr[x + 2] +
                        filter[3] * src_ptr[x + 3]) >> 4;

            tmp_ptr[x]     = (int16_t)val1;
            if (x + 1 < width)
                tmp_ptr[x + 1] = (int16_t)val2;
        }
        src_ptr += srcstride;
        tmp_ptr += 64;
    }
}
