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
    // Variant 2: Strided memory access — process every second element first, then the in-betweens (interleaved stride pattern)
    for (y = 0; y < height + 3; y++) {
        uint8_t *src_row = src + y * srcstride;
        int16_t *tmp_row = tmp + y * 64;

        // First pass: even indices (stride of 2)
        for (x = 0; x < width; x += 2) {
            tmp_row[x] = (int16_t)((filter[0] * src_row[x - 1] + filter[1] * src_row[x] + 
                                   filter[2] * src_row[x + 1] + filter[3] * src_row[x + 2]) >> 0);
        }

        // Second pass: odd indices (offset by 1, same stride)
        for (x = 1; x < width; x += 2) {
            tmp_row[x] = (int16_t)((filter[0] * src_row[x - 1] + filter[1] * src_row[x] + 
                                   filter[2] * src_row[x + 1] + filter[3] * src_row[x + 2]) >> 0);
        }
    }
}
